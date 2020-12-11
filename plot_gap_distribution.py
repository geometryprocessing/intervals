import matplotlib as mpl
mpl.use('Agg')
from fractions import Fraction
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import FixedLocator
import platform
import sys
import math
import statistics
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

def plot_raw(datas, test_name, system = "mac"):
    plt.rc('xtick', labelsize=7)    # fontsize of the tick labels
    plt.rc('ytick', labelsize=10)    # fontsize of the tick labels
    plt.rc('legend', fontsize=10)    # fontsize of the tick labels
    bar_width = 0.5/(len(datas))

    all_items = []
    for item in datas:
        all_items += datas[item]
    average = statistics.median(all_items)
    average_log = int(math.floor(math.log10(average)))
    if average <= 0 :
        average = sum(all_items) * 1.0 / len(all_items)
        if average <=0:
            average = math.pow(10, -16)
    limit_down = average_log - 4
    limit_up = average_log + 4
    count = 0
    bins = list(range(21))
    bins = [x * 0.5 + limit_down - 1 for x in bins]
    # print(bins)
    # print(len(bins))
    negative_count = 0
    ax = plt.axes()
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    plt.xlim([limit_down - 1, limit_up + 2.5])
    plt.ylim([0, 100])
    plt.xticks([limit_down - 1] + list(range(limit_down, limit_up + 2)),  [r'$\leq10^{' + str(limit_down) + r'}$'] + [r'$10^{' + str(x) + r'}$' for x in list(range(limit_down, limit_up))] + [r'$\geq10^{' + str(limit_up) + r'}$', "EMPTY"])
    for item in datas:
        belows = 0
        ranges = [0] * 16
        aboves = 0
        negatives = 0
        
        for gap in datas[item]:
            if gap < 0:
                negatives += 1
            elif gap == 0:
                belows += 1
            else:
                ## compute the log value
                log_value = math.log10(gap)
                if log_value <= limit_down:
                    belows += 1
                elif log_value >= limit_up:
                    aboves += 1
                else:
                    position = int((log_value - limit_down) * 2)
                    ranges[position] += 1
        belows = belows * 100.0 / len(datas[item])
        ranges = [x * 100.0 / len(datas[item]) for x in ranges]
        aboves = aboves * 100.0 / len(datas[item])
        negatives = negatives * 100.0 / len(datas[item])
        # print(belows)
        # print(ranges)
        # print(aboves)
        # print(negatives)

        bar = plt.bar([x+bar_width / 2 + bar_width * count for x in bins], [0] * 2 + ranges + [0] * 3, label=item, color=colors[count], alpha=1.0, width=bar_width)
        bar = plt.bar([x+bar_width * 1 + bar_width * 2 * count for x in bins], [belows, 0] + [0] * 16 + [aboves, 0] + [negatives] , color=colors[count], alpha=1.0, width=bar_width *2)

        if (negatives > 0):
            rect = bar[-1]
            plt.text(limit_up + 1.5, rect.get_height(), ('%s:\n%f' % (item, negatives)).rstrip('0').rstrip('.')+"%"+"\n\n"*negative_count, ha='center', va='bottom')
            negative_count += 1
        count += 1


    plt.legend(prop={'size': 6})
    plt.title(test_name)
    # plt.show()
    save_plot_name = "graphs/raw/" + test_name + "_gap_raw_" + system + ".pdf"
    plt.savefig(save_plot_name, bbox_inches='tight',
                pad_inches=0, dpi=200)
    plt.close()
    print(test_name + " raw interval size graph generated")
   

    




def plot_comp(datas, test_name, system = "mac"):
    pass


def compute_comparison(base, num):
    frac = 1.0
    if (base == 0 and num == 0):
        frac = 1
    elif (base == 0 and num != 0):
        frac = 999
    elif (base != 0 and num == 0):
        frac = 0
    else:
        frac = float(num / base)
    return frac

def plot_data(file_name, system = "mac"):
    f = open(file_name, 'r')
    last_test_name = None
    datas = {}
    numerator = 1
    denominator = 1
    for line in f:
        splitted = line.strip().split(", ")
        test_name = ", ".join(splitted[1:-2])
        method_name = splitted[-2]
        if last_test_name != test_name:
            if last_test_name!=None:
                plot_raw(datas, last_test_name, system)
                plot_comp(datas, last_test_name, system)
            ## clear data
            datas = {}
            ## set the new test name
            last_test_name = test_name
            method_names.clear()
        
        ## put method name in dictionary
        if not method_name in method_names:
            method_names.append(method_name)
            datas[method_name] = []
        

        ## get the gap size in numerator and denominator
        if (len(splitted[-1].split("/")) == 2):
            numerator = int(splitted[-1].split("/")[0])
            denominator = int(splitted[-1].split("/")[1])
        else:
            numerator = int(splitted[-1].split("/")[0])
            denominator = 1
        datas[method_name].append(float(Fraction(numerator, denominator)))
    plot_raw(datas, last_test_name, system)
    plot_comp(datas, last_test_name, system)



def main():
    plot_data("build/gaps.txt", str(platform.platform()))


if __name__ == "__main__":
    main()
