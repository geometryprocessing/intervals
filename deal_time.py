import pandas as pd
import platform
def to_table(file_name):
    system = str(platform.platform())
    test_names = []
    method_names = []
    all_datas = {}
    f = open(file_name)
    for line in f:
        splitted = line.strip().split(",")
        test_name = splitted[1]
        method_name = splitted[2]
        raw_time = splitted[3].split("us")[0]
        fraction = splitted[4].split("x")[0]
        if (not test_name in all_datas):
            all_datas[test_name] = {}
            test_names.append(test_name)
        if (not method_name in method_names):
                method_names.append(method_name)
        all_datas[test_name][method_name] = [float(raw_time), float(fraction)]
    
    print("Raw timing on %s: "%system)
    raw_datas = {}
    for test in test_names:
        raw_datas[test] = [all_datas[test][x][0] for x in method_names]
    raw_datas_table = pd.DataFrame.from_dict(raw_datas, orient='index', columns=method_names)
    raw_datas_table = raw_datas_table.reindex(test_names)
    print(raw_datas_table)

    print("Comparing to filib c version on %s: "%system)
    comp_datas = {}
    for test in test_names:
        comp_datas[test] = [all_datas[test][x][1] for x in method_names]
    comp_datas_table = pd.DataFrame.from_dict(comp_datas, orient='index', columns=method_names)
    comp_datas_table = comp_datas_table.reindex(test_names)
    print(comp_datas_table)


    # print(all_datas)


to_table("build/time.txt")
            
        
        
