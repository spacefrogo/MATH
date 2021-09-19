#!/usr/bin/env python3

from sys import argv, stderr
import csv
from operator import add
from math import sqrt, fsum

MIL: int = 1_000_000


def gsum(x):
    return fsum(x)

def gsum_squared(x):
    return fsum((i ** 2 for i in x))

def squared_gsum(x):
    return gsum(x) ** 2

def gsum_xy(x, y):
    return fsum((int(i) for i in
        [a * b for (a, b) in zip(x, y)] + max(x, x, key=len)[min(len(data), len(y)):]
        ))


def rmsqdev(calc, x, date):
    return sqrt(fsum(
            (((e * calc[1]) + calc[0])
                - x[i] / MIL) ** 2
               for i, e in enumerate(date))
               / len(date))

def rmsqdev_neg(calc, x, date):
    return sqrt(fsum(
            (((e - calc[0]) / calc[1])
                - x[i] / MIL) ** 2
               for i, e in enumerate(date))
               / len(date))

def linreg(is_fit2, x, header):
    a = ((gsum(x) * gsum_squared(header)
        - gsum(header) * gsum_xy(x, header))
            / (len(header) * gsum_squared(header)
                - squared_gsum(header)))
    b = ((len(header) * gsum_xy(x, header)
        - gsum(x) * gsum(header))
            / (len(header) * gsum_squared(header)
                - squared_gsum(header)))
    return [a, b * MIL] if is_fit2 else [a / MIL, b / MIL]

def fit1(data, header):
    calc = linreg(False, data, header)
    rmsqd = rmsqdev(calc, data, header)
    print("Fit1"
        , f"	Y = {calc[1]:.2f} X "
            + (f'+ {calc[0]:.2f}' if calc[0] >= 0 else f'- {calc[0] * -1:.2f}')
        , f"	Root-mean-square deviation: {rmsqd:.2f}"
        , f"	Population in 2050: {2050 * calc[1] + calc[0]:.2f}"
        , sep='\n', end='\n')
    return rmsqd

def fit2(data, header):
    calc = linreg(True, data, header)
    rmsqd = rmsqdev_neg(calc, data, header)
    print("Fit2"
        , f"	X = {calc[1]:.2f} Y "
            + (f'+ {calc[0]:.2f}' if calc[0] >= 0 else f'- {calc[0] * -1:.2f}')
        , f"	Root-mean-square deviation: {rmsqd:.2f}"
        , f"	Population in 2050: {(2050 - calc[0]) / calc[1]:.2f}"
        , sep='\n', end='\n')
    return rmsqd

def fill_data(data):
    population, header = ([], [])
    for row in data:
        for country in argv[1:]:
            if country == row[1]:
                if len(population) == 0:
                    population.extend(list(map(int, row[2:])))
                    header.extend(list(map(int, data[0][2:])))
                else:
                    population = list(map(add, population, row[2:]))
    return population, header, [row[0] for row in data
            for country in argv[1:] if country == row[1]]


if __name__ == "__main__":
    try:
        if len(argv) < 2:
            print("invalid arguments, try `-h`", file=stderr)
            exit(84)
        if argv[1] == '-h':
            print("USAGE", "	./207demography code [...]", "",
                    "DESCRIPTION", "	code	country code", sep='\n')
            exit(0)
        for a in argv[1:]:
            if len(a) != 3 or not a.isupper():
                print("invalid country code: ", a)
                exit(84)

        with open("207demography_data.csv", newline='') as infile:
            data = [row for row in csv.reader(infile, delimiter=';')]
        population, header, country = fill_data(data)
        print("Country:", ', '.join(country))
        fits = [ fit1(population, header)
               , fit2(population, header)
               ]
        print("Correlation: {:.4f}".format(fits[0] / fits[1]))
    except Exception as e:
        print(e, file=stderr)
        exit(84)
