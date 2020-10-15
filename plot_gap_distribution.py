from fractions import Fraction
import matplotlib.pyplot as plt
import scipy.stats as st
import numpy as np
try:
    import cPickle as pickle
except ImportError:  # Python 3.x
    import pickle
test_names = []
method_names = []
colors = ["#FFBF00", "#2274A5", "#32936F", "#D00000", "#1C3144"]

bin_size = 72  # the last one is for outliers

bins = [x/10.0 for x in list(range(0, bin_size, 1))]
# print(bins)


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
            all_datas[test_name][method_name] = [0]*bin_size
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
            if position < 61:
                all_datas[test_name][method_name][position] += 1
            else:
                outlier_file.write(base_line)
                outlier_file.write(line)
                outlier_file.write("FRACTION: "+str(frac)+"\n")
                all_datas[test_name][method_name][-1] += 1

        count += 1

    with open("datas/comparison_"+system+".p", 'wb') as fp:
        pickle.dump(all_datas, fp, protocol=pickle.HIGHEST_PROTOCOL)

    outlier_file.close()
    return all_datas


def plot_comparisons(datas, saved_file="", system="mac"):
    if saved_file != "":
        with open(saved_file, 'rb') as fp:
            datas = pickle.load(fp)
            for item in datas:
                if not item in test_names:
                    test_names.append(item)
                for method in datas[item]:
                    if not method in method_names:
                        method_names.append(method)

    for test in datas:
        ax = plt.axes()
        outlier_count = 0
        for i in range(1, len(method_names)):
            method = method_names[i]
            comp = datas[test][method]
            total_count = sum(comp)
            comp = [float(x)*1.0 / total_count for x in comp]
            bar = plt.bar(bins, comp, label=method +
                          " / " + method_names[0], color=colors[i-1], alpha=0.8, width=0.1)
            rect = bar[-1]
            height = rect.get_height()
            if height > 0:
                # print(comp[-1])
                plt.text(rect.get_x() + rect.get_width()/2.0, height,
                         ('%s:\n%f' % (method, comp[-1] * 100)).rstrip('0').rstrip('.')+"%"+"\n\n"*outlier_count, ha='center', va='bottom')
                outlier_count+=1
            # plt.hist(comp, bins = bins, label=method +
            #          " / " + method_names[0], color=colors[i-1], alpha=0.8)
            plt.legend()

        plt.xlim([0, 8])
        plt.ylim([0, 1])
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        plt.xticks(list(range(0, 8)), list(range(0, 7))+[">6"])
        plt.title(test)
        # plt.text(7, 0, "OUTLIER")
        save_plot_name = "graphs/" + test + "_gap_" + system + ".pdf"
        # print(save_plot_name)
        plt.savefig(save_plot_name, bbox_inches='tight',
                    pad_inches=0, dpi=2000)
        plt.close()


# datas = populate_data("build/gaps_linux.txt", system="linux")
# plot_comparisons([], system="linux")

datas = populate_data("build/gaps_mac_sqrt.txt", system="mac")
plot_comparisons(datas, system="mac")
