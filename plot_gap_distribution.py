import matplotlib as mpl
mpl.use('Agg')
from fractions import Fraction
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import FixedLocator
import platform
import sys
import math
try:
    import cPickle as pickle
except ImportError:  # Python 3.x
    import pickle


test_names = []
method_names = []
colors = ["#F78154", "#1C3144", "#2274A5", "#32936F",
          "#D00000", "#FFBF00", "#8D2AB7", "#27182E", "#232534"]

# the ones that we actually care about, in this case we care about distribution between 0 to 3
bin_size_comp = 30
actual_bin_size_comp = 50  # position 40 and 50 are for outliers and negative intervals
bins_comp = [x/10.0 for x in list(range(0, actual_bin_size_comp+1, 1))]


# < -16, -16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, >=3, placeholder, empty
bin_size_raw = 22  # the ones that we actually care about, in this case we care about distribution between 10^-17 to 10^3
actual_bin_size_raw = 23  # position 50 for outliers, position 60 for negatives
bins_raw = list(range(-17, 6, 1))


def populate_data(file_name, system="mac"):
    all_datas_comp = {}
    all_datas_raw = {}
    f = open(file_name)
    count = 0
    base_line = ""
    base = Fraction(1, 1)
    for line in f:
        if ((count+1) % 2500000 == 0):
            print(count+1)
            # break
        splitted = line.strip().split(", ")
        test_name = ", ".join(splitted[1:-2])
        method_name = splitted[-2]
        numerator = 1
        denominator = 1
        if (len(splitted[-1].split("/")) == 2):
            numerator = int(splitted[-1].split("/")[0])
            denominator = int(splitted[-1].split("/")[1])
        else:
            numerator = int(splitted[-1].split("/")[0])
        if (not test_name in all_datas_comp):
            all_datas_comp[test_name] = {}
            all_datas_raw[test_name] = {}
            test_names.append(test_name)
        if (not method_name in all_datas_comp[test_name]):
            all_datas_comp[test_name][method_name] = [0] * (actual_bin_size_comp + 1)
            all_datas_raw[test_name][method_name] = [0] * actual_bin_size_raw
            if (not method_name in method_names):
                method_names.append(method_name)

        # get the comparisons
        if method_name == method_names[0]:
            # if this is the base method, we use it as our base number
            base_line = line
            base = Fraction(numerator, denominator)
        else:
            # else, we need to get the fraction
            length = Fraction(numerator, denominator)
            frac = 1.0
            if (base == 0 and length == 0):
                frac = 1
            elif (base == 0 and length != 0):
                frac = 999
            elif (base != 0 and length == 0):
                frac = 0
            else:
                frac = float(length / base)
            position = int(frac / 0.1)
            if position <= bin_size_comp and position >= 0:
                # within 0 to 3
                all_datas_comp[test_name][method_name][position] += 1
            elif position < 0:
                all_datas_comp[test_name][method_name][actual_bin_size_comp] += 1
            else:
                all_datas_comp[test_name][method_name][actual_bin_size_comp-10] += 1

        # get the raw data
        length = float(Fraction(numerator, denominator))
        log_value = None

        if length == 0:
            log_value = -17
        elif length > 0:
            log_value = math.log10(length)
            if log_value < -16:
                log_value = -17

        if log_value == None:
            all_datas_raw[test_name][method_name][actual_bin_size_raw - 1] += 1
        elif log_value < 3:
            position = math.floor(log_value) + 17
            all_datas_raw[test_name][method_name][position] += 1
        elif log_value >= 3:
            all_datas_raw[test_name][method_name][actual_bin_size_raw - 3] += 1

        count += 1

    with open("datas/comparison_"+system+".p", 'wb') as fp:
        pickle.dump(all_datas_comp, fp, protocol=pickle.HIGHEST_PROTOCOL)

    with open("datas/raw_"+system+".p", 'wb') as fp:
        pickle.dump(all_datas_raw, fp, protocol=pickle.HIGHEST_PROTOCOL)

    return all_datas_comp, all_datas_raw


def read_saved_file(saved_file_comp, saved_file_raw):
    datas_comp = {}
    with open(saved_file_comp, 'rb') as fp:
        datas_comp = pickle.load(fp)
        for item in datas_comp:
            if not item in test_names:
                test_names.append(item)
            for method in datas_comp[item]:
                if not method in method_names:
                    method_names.append(method)
    datas_raw = {}
    with open(saved_file_raw, 'rb') as fp:
        datas_raw = pickle.load(fp)
        for item in datas_raw:
            if not item in test_names:
                test_names.append(item)
            for method in datas_raw[item]:
                if not method in method_names:
                    method_names.append(method)
    return datas_comp, datas_raw


def plot_comparisons(datas_comp, system="mac"):
    bar_width = 0.1/(len(method_names)-1)
    for test in datas_comp:
        ax = plt.axes()
        negative_count = 0
        for i in range(1, len(method_names)):
            method = method_names[i]
            comp = datas_comp[test][method]
            total_count = sum(comp)
            comp = [float(x)*100.0 / total_count for x in comp]
            bar = plt.bar([x+bar_width/2 + bar_width*(i-1) for x in bins_comp], comp, label=method,
                          color=colors[i], alpha=1.0, width=bar_width)
            # put text for outliers
            rect = bar[actual_bin_size_comp-10]
            height = rect.get_height()
            # if height > 0:
            #     plt.text(rect.get_x() + rect.get_width()/2.0, height,
            #              ('%s:\n%f' % (method, comp[actual_bin_size_comp-10] * 100)).rstrip('0').rstrip('.')+"%", ha='center', va='bottom')
            #     outlier_count += 1
            # put text for negative intervals
            rect = bar[actual_bin_size_comp]
            height = rect.get_height()
            if height > 0:
                plt.text(rect.get_x() + rect.get_width()/2.0, height,
                         ('%s:\n%f' % (method, comp[actual_bin_size_comp] * 100)).rstrip('0').rstrip('.')+"%", ha='center', va='bottom')
                negative_count += 1
            plt.legend(prop={'size': 6})

        plt.xlim([0, int(bin_size_comp/10 + 3)])
        plt.ylim([0, 100])
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        plt.xticks(list(range(0, int(bin_size_comp/10 + 3))), list(range(0,
                                                                         int(bin_size_comp/10 + 1)))+[">" + str(int(bin_size_comp/10))] + ["EMPTY"])
        ax.xaxis.set_minor_locator(FixedLocator(
            [x*0.1 for x in list(range(bin_size_comp))]))
        plt.title(test)
        # plt.text(7, 0, "OUTLIER")
        save_plot_name = "graphs/comp/" + test + "_gap_comp_" + system + ".pdf"
        # print(save_plot_name)
        plt.savefig(save_plot_name, bbox_inches='tight',
                    pad_inches=0, dpi=2000)
        plt.close()


def plot_raws(datas_raw, system="mac"):
    plt.rc('xtick', labelsize=7)    # fontsize of the tick labels
    plt.rc('ytick', labelsize=10)    # fontsize of the tick labels
    plt.rc('legend', fontsize=10)    # fontsize of the tick labels
    bar_width = 1.0/(len(method_names))
    for test in datas_raw:
        ax = plt.axes()
        negative_count = 0
        for i in range(len(method_names)):
            method = method_names[i]
            all_data = datas_raw[test][method]
            total_count = sum(all_data)
            all_data = [float(x)*100.0 / total_count for x in all_data]
            bar = plt.bar([x+bar_width/2 + bar_width*i for x in bins_raw], all_data, label=method,
                          color=colors[i], alpha=1.0, width=bar_width)
            # if height > 0:
            #     plt.text(rect.get_x() + rect.get_width()/2.0, height,
            #              ('%s:\n%f' % (method, all_data[actual_bin_size_raw-10] * 100)).rstrip('0').rstrip('.')+"%", ha='center', va='bottom')
            #     outlier_count += 1
            # put text for negative intervals
            rect = bar[actual_bin_size_raw-1]
            height = rect.get_height()
            if height > 0:
                plt.text(rect.get_x() + rect.get_width()/2.0 - bar_width*i, height,
                         ('%s:\n%f' % (method, all_data[actual_bin_size_raw-1] * 100)).rstrip('0').rstrip('.')+"%"+"\n\n"*negative_count, ha='center', va='bottom')
                negative_count += 1
            plt.legend(prop={'size': 6})

        plt.xlim([-17, 6])
        plt.ylim([0, 100])
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        plt.xticks(list(range(-17, 4, 1))+[5], [r'$\leq10^{-16}$'] + [r'$10^{' + str(
            x) + r'}$' if x % 2 == 1 else "" for x in list(range(-16, 3, 1))]+[r"$\geq10^3$", "EMPTY"])
        plt.title(test)
        # plt.show()
        save_plot_name = "graphs/raw/" + test + "_gap_raw_" + system + ".pdf"
        plt.savefig(save_plot_name, bbox_inches='tight',
                    pad_inches=0, dpi=200)
        plt.close()


def main():
    datas_comp = None
    datas_raw = None
    system = str(platform.platform())
    # load data from pickle file
    if len(sys.argv) > 1:
        datas_comp, datas_raw = read_saved_file(sys.argv[1], sys.argv[2])
    else:
        datas_comp, datas_raw = populate_data("build/gaps.txt", system=system)
    plot_comparisons(datas_comp, system=system)
    plot_raws(datas_raw, system=system)


if __name__ == "__main__":
    main()
