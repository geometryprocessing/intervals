import random
from decimal import *
from fractions import Fraction
import os
import re

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443,
          449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]


getcontext().prec = 32


def return_command(op, al, au, bl, bu):
    return "cd build && ./unit_tests -o {} --aln {} --ald {} --aun {} --aud {} --bln {} --bld {} --bun {} --bud {} && cd ..".format(op, al.numerator, al.denominator, au.numerator, au.denominator, bl.numerator, bl.denominator, bu.numerator, bu.denominator)


def within_range(lower, upper, nums):
    for item in nums:
        if item < lower or item > upper:
            print("Value not within range: {}".format(frac_to_dec(item)))
            return False
    return True


def frac_to_dec(frac):
    return Decimal(frac.numerator)/Decimal(frac.denominator)


def test_add():
    aln = random.choice(primes)
    ald = random.choice(primes)
    aun = random.choice(primes)
    aud = random.choice(primes)
    bln = random.choice(primes)
    bld = random.choice(primes)
    bun = random.choice(primes)
    bud = random.choice(primes)

    al = Fraction(aln, ald) * (1 if random.random() > 0.5 else -1)
    au = Fraction(aun, aud) * (1 if random.random() > 0.5 else -1)

    bl = Fraction(bln, bld) * (1 if random.random() > 0.5 else -1)
    bu = Fraction(bun, bud) * (1 if random.random() > 0.5 else -1)

    if (al > au):
        tmp = Fraction(au.numerator, au.denominator)
        au = al
        al = tmp

    if (bl > bu):
        tmp = Fraction(bu.numerator, bu.denominator)
        bu = bl
        bl = tmp

    command = return_command(0, al, au, bl, bu)
    stream = os.popen(command)
    output = stream.read()
    result = output.split("\n")
    result_split = {}
    range = []
    for item in result:
        if ("interval 1 from") in item:
            result_split["interval1"] = item
        elif ("interval 2 from") in item:
            result_split["interval2"] = item
        elif "result from " in item:
            range = re.findall(r"[-+]?\d*\.\d+|\d+", item)
    lower = Decimal(range[0])
    upper = Decimal(range[1])
    print(result_split["interval1"])
    print("True interval 1 from {} to {}, fraction from {} to {}".format(
        frac_to_dec(al), frac_to_dec(au), al, au))
    print(result_split["interval2"])
    print("True interval 2 from {} to {}, fraction from {} to {}".format(
        frac_to_dec(bl), frac_to_dec(bu), bl, bu))
    print("Computed addition from {} to {}".format(lower, upper))
    within = within_range(lower, upper, [al+bl, au+bu])
    print("Within range: {}".format(within))


def test_mult():
    aln = random.choice(primes)
    ald = random.choice(primes)
    aun = random.choice(primes)
    aud = random.choice(primes)
    bln = random.choice(primes)
    bld = random.choice(primes)
    bun = random.choice(primes)
    bud = random.choice(primes)

    al = Fraction(aln, ald) * (1 if random.random() > 0.5 else -1)
    au = Fraction(aun, aud) * (1 if random.random() > 0.5 else -1)

    bl = Fraction(bln, bld) * (1 if random.random() > 0.5 else -1)
    bu = Fraction(bun, bud) * (1 if random.random() > 0.5 else -1)

    if (al > au):
        tmp = Fraction(au.numerator, au.denominator)
        au = al
        al = tmp

    if (bl > bu):
        tmp = Fraction(bu.numerator, bu.denominator)
        bu = bl
        bl = tmp

    command = return_command(2, al, au, bl, bu)
    stream = os.popen(command)
    output = stream.read()
    result = output.split("\n")
    result_split = {}
    range = []
    for item in result:
        if ("interval 1 from") in item:
            result_split["interval1"] = item
        elif ("interval 2 from") in item:
            result_split["interval2"] = item
        elif "result from " in item:
            range = re.findall(r"[-+]?\d*\.\d+|\d+", item)
    lower = Decimal(range[0])
    upper = Decimal(range[1])
    print(result_split["interval1"])
    print("True interval 1 from {} to {}, fraction from {} to {}".format(
        frac_to_dec(al), frac_to_dec(au), al, au))
    print(result_split["interval2"])
    print("True interval 2 from {} to {}, fraction from {} to {}".format(
        frac_to_dec(bl), frac_to_dec(bu), bl, bu))
    print("Computed multiplication from {} to {}".format(lower, upper))
    within = within_range(lower, upper, [al*bl, al*bu, au*bl, au*bu])
    print("Within range: {}".format(within))


test_add()
print()
test_mult()
