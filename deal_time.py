import matplotlib as mpl
mpl.use('Agg')
import matplotlib.pyplot as plt
import sys
import platform
import pandas as pd


pd.set_option('display.float_format', lambda x: '%.2f' % x)
plt.rc('xtick', labelsize=5)    # fontsize of the tick labels
plt.rc('ytick', labelsize=10)    # fontsize of the tick labels
plt.rc('legend', fontsize=10)    # fontsize of the tick labels


def to_table(file_name):
    system = str(platform.platform())
    test_names = []
    method_names = []
    all_datas = {}
    f = open(file_name)
    for line in f:
        splitted = line.strip().split(",")
        test_name = splitted[1]
        method_name = splitted[2].replace(" METHOD", "")
        raw_time = float(splitted[3].split("us")[0])/1000
        fraction = splitted[4].split("x")[0]
        if (not test_name in all_datas):
            all_datas[test_name] = {}
            test_names.append(test_name)
        if (not method_name in method_names):
            method_names.append(method_name)
        all_datas[test_name][method_name] = [float(raw_time), float(fraction)]

    print("Raw timing on %s: " % system)
    raw_datas = {}
    for test in test_names:
        raw_datas[test] = [all_datas[test][x][0] for x in method_names]
    raw_datas_table = pd.DataFrame.from_dict(
        raw_datas, orient='index', columns=method_names)
    raw_datas_table = raw_datas_table.reindex(test_names)
    print(raw_datas_table)
    print(raw_datas_table.to_latex())

    print("Comparing to filib c version on %s: " % system)
    comp_datas = {}
    for test in test_names:
        comp_datas[test] = [all_datas[test][x][1] for x in method_names]
    comp_datas_table = pd.DataFrame.from_dict(
        comp_datas, orient='index', columns=method_names)
    comp_datas_table = comp_datas_table.reindex(test_names)
    print(comp_datas_table)
    print(comp_datas_table.to_latex())


def plot_table(file_name):
    system = str(platform.platform())
    test_names = []
    method_names = []
    all_datas = {}
    f = open(file_name)
    for line in f:
        splitted = line.strip().split(",")
        test_name = splitted[1].split()
        # print(test_name)
        if len(test_name) == 3:
            test_name = test_name[0]+test_name[2]
        else:
            test_name = splitted[1]
        method_name = splitted[2].replace(" METHOD", "")
        raw_time = float(splitted[3].split("us")[0])/1000
        fraction = splitted[4].split("x")[0]
        if (not test_name in all_datas):
            all_datas[test_name] = {}
            test_names.append(test_name)
        if (not method_name in method_names):
            method_names.append(method_name)
        all_datas[test_name][method_name] = [float(raw_time), float(fraction)]

    raw_datas = {}
    for test in test_names:
        raw_datas[test] = [all_datas[test][x][0] for x in method_names]
    raw_datas_table = pd.DataFrame.from_dict(
        raw_datas, orient='index', columns=method_names)
    raw_datas_table = raw_datas_table.reindex(test_names)

    comp_datas = {}
    for test in test_names:
        comp_datas[test] = [all_datas[test][x][1] for x in method_names]
    comp_datas_table = pd.DataFrame.from_dict(
        comp_datas, orient='index', columns=method_names)
    comp_datas_table = comp_datas_table.reindex(test_names)

    single_op_raw_time = raw_datas_table[0:8]
    arith_comp_raw_time = raw_datas_table[8:18]
    mix_comp_raw_time = raw_datas_table[18:28]
    ax = single_op_raw_time.plot.bar(rot=0)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    save_plot_name = "graphs/time/" + "single_operations_time_" + system + ".pdf"
    plt.savefig(save_plot_name, bbox_inches='tight',
                pad_inches=0, dpi=400,)
    plt.close()
    ax = arith_comp_raw_time.plot.bar(rot=0)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    save_plot_name = "graphs/time/" + "comp_arith_time_" + system + ".pdf"
    plt.savefig(save_plot_name, bbox_inches='tight',
                pad_inches=0, dpi=400)
    plt.close()
    ax = mix_comp_raw_time.plot.bar(rot=0)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    save_plot_name = "graphs/time/" + "comp_all_time_" + system + ".pdf"
    plt.savefig(save_plot_name, bbox_inches='tight',
                pad_inches=0, dpi=400)
    plt.close()


def main():
    if len(sys.argv) > 1:
        to_table(sys.argv[1])
        plot_table(sys.argv[1])
    else:
        to_table("build/time.txt")
        plot_table("build/time.txt")


if __name__ == "__main__":
    main()
