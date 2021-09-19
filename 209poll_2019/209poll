#!/usr/bin/env python3

from sys import argv, stderr
from math import sqrt

A95 = 1.96
A99 = 2.58


def check_help():
    if len(argv) == 2 and argv[1] == "-h":
        print("USAGE", "	./209poll pSize sSize p", "",
              "DESCRIPTION",
              "	pSize	size of the population",
              "	sSize	size of the sample (supposed to be representative)",
              "	p	percentage of voting intentions for a specific candidate")
    else:
        print("Invalid argument number", file=stderr)
        exit(84)


def check_args():
    pSize, sSize, p = int(argv[1]), int(argv[2]), float(argv[3])

    if not 0 < pSize:
        raise ValueError("pSize doesn't follow constraint: 0 < pSize")
    if not 0 < sSize < pSize:
        raise ValueError("sSize doesn't follow constraint: 0 < sSize < pSize")
    if not 0 < p < 100:
        raise ValueError("p must be between 0% and 100%")
    if pSize - 1 < 0:
        raise ValueError("division by zero (pSize)")

    return pSize, sSize, p


def show_min(sample):
    return "0%" if sample < 0 else f"{sample:0.2f}%"


def show_max(sample):
    return "100%" if sample > 100 else f"{sample:0.2f}%"


def vals(pSize, sSize, p):
    p /= 100
    variance = (((p * (1 - p)) / sSize)
                * ((pSize - sSize) / (pSize - 1)))
    p1 = A95 * sqrt(variance) * 100
    p2 = A99 * sqrt(variance) * 100

    res95 = show_min(p * 100 - p1), show_max(p * 100 + p1)
    res99 = show_min(p * 100 - p2), show_max(p * 100 + p2)

    return variance, res95, res99


if __name__ == "__main__":
    if len(argv) != 4:
        check_help()

    try:
        pSize, sSize, p = check_args()

        variance, res95, res99 = vals(pSize, sSize, p)

        print(f"population size:		{pSize}",
                f"sample size:			{sSize}",
                f"voting intentions:		{argv[3]}%",
                f"variance:			{variance:0.6f}",
                "95% confidence interval:	[{}; {}]" .format(*res95),
                "99% confidence interval:	[{}; {}]".format(*res99),
                sep='\n')
        exit(0)

    except Exception as e:
        print(e, file=stderr)
        exit(84)
