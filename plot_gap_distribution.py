import sys
import platform
from matplotlib.ticker import FixedLocator
import matplotlib.pyplot as plt
import numpy as np
from fractions import Fraction
import matplotlib as mpl
mpl.use('Agg')
try:
    import cPickle as pickle
except ImportError:  # Python 3.x
    import pickle


test_names = []
method_names = []
colors = ["#1C3144", "#2274A5", "#32936F", "#D00000", "#FFBF00"]

bin_size = 30  # the ones that we actually care about, in this case we care about distribution between 0 to 3
actual_bin_size = 50  # position 40 and 50 are for outliers and negative intervals
bins = [x/10.0 for x in list(range(0, actual_bin_size+1, 1))]


def populate_data(file_name, system="mac"):
    all_datas = {}
    f = open(file_name)
    count = 0
    base_line = ""
    base = Fraction(1, 1)
    outlier_file = open("datas/outliers_gap_"+system+".txt", 'w')
    for line in f:
        if ((count+1) % 2500000 == 0):
            print(count+1)
            # break
        splitted = line.strip().split(", ")
        test_name = splitted[1]
        method_name = splitted[2]
        numerator = 1
        denominator = 1
        if (len(splitted[3].split("/")) == 2):
            numerator = int(splitted[3].split("/")[0])
            denominator = int(splitted[3].split("/")[1])
        else:
            numerator = int(splitted[3].split("/")[0])
        if (not test_name in all_datas):
            all_datas[test_name] = {}
            test_names.append(test_name)
        if (not method_name in all_datas[test_name]):
            all_datas[test_name][method_name] = [0] * (actual_bin_size + 1)
            if (not method_name in method_names):
                method_names.append(method_name)
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

            if position <= bin_size and position >= 0:
                # within 0 to 3
                all_datas[test_name][method_name][position] += 1
            elif position < 0:
                # negative interval
                outlier_file.write(base_line)
                outlier_file.write(line)
                outlier_file.write("FRACTION: "+str(frac)+"\n")
                all_datas[test_name][method_name][actual_bin_size] += 1
            else:
                outlier_file.write(base_line)
                outlier_file.write(line)
                outlier_file.write("FRACTION: "+str(frac)+"\n")
                all_datas[test_name][method_name][actual_bin_size-10] += 1

        count += 1

    with open("datas/comparison_"+system+".p", 'wb') as fp:
        pickle.dump(all_datas, fp, protocol=pickle.HIGHEST_PROTOCOL)

    outlier_file.close()
    return all_datas


def read_saved_file(saved_file):
    datas = {}
    with open(saved_file, 'rb') as fp:
        datas = pickle.load(fp)
        for item in datas:
            if not item in test_names:
                test_names.append(item)
            for method in datas[item]:
                if not method in method_names:
                    method_names.append(method)
    return datas


def plot_comparisons(datas, system="mac"):
    bar_width = 0.1/(len(method_names)-1)
    for test in datas:
        ax = plt.axes()
        outlier_count = 0
        negative_count = 0
        for i in range(1, len(method_names)):
            method = method_names[i]
            comp = datas[test][method]
            total_count = sum(comp)
            comp = [float(x)*1.0 / total_count for x in comp]
            bar = plt.bar([x+bar_width/2 + bar_width*(i-1) for x in bins], comp, label=method,
                          color=colors[i-1], alpha=1.0, width=bar_width)
            # put text for outliers
            rect = bar[actual_bin_size-10]
            height = rect.get_height()
            if height > 0:
                plt.text(rect.get_x() + rect.get_width()/2.0, height,
                         ('%s:\n%f' % (method, comp[actual_bin_size-10] * 100)).rstrip('0').rstrip('.')+"%", ha='center', va='bottom')
                outlier_count += 1
            # put text for negative intervals
            rect = bar[actual_bin_size]
            height = rect.get_height()
            if height > 0:
                plt.text(rect.get_x() + rect.get_width()/2.0, height,
                         ('%s:\n%f' % (method, comp[actual_bin_size] * 100)).rstrip('0').rstrip('.')+"%", ha='center', va='bottom')
                negative_count += 1
            plt.legend(prop={'size': 6})

        plt.xlim([0, int(bin_size/10 + 3)])
        plt.ylim([0, 1])
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        plt.xticks(list(range(0, int(bin_size/10 + 3))), list(range(0,
                                                                    int(bin_size/10 + 1)))+[">" + str(int(bin_size/10))] + ["<0"])
        ax.xaxis.set_minor_locator(FixedLocator(
            [x*0.1 for x in list(range(bin_size))]))
        plt.title(test)
        # plt.text(7, 0, "OUTLIER")
        save_plot_name = "graphs/" + test + "_gap_" + system + ".pdf"
        # print(save_plot_name)
        plt.savefig(save_plot_name, bbox_inches='tight',
                    pad_inches=0, dpi=2000)
        plt.close()


def main():
    datas = None
    system = str(platform.platform())
    # load data from pickle file
    if len(sys.argv) > 1:
        datas = read_saved_file(sys.argv[1])
    else:
        datas = populate_data("build/gaps.txt", system=system)
    plot_comparisons(datas, system=system)

if __name__ == "__main__":
    main()
