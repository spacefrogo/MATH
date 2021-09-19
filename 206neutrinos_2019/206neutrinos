#!/usr/bin/env python3

from sys import argv, stderr
from math import sqrt

def neutrinos(n, arithM, hM, sd):
    quadM = 0.0
    while True:
        line = input("Enter next value: ")
        if line == "END":
            exit(0)
        else:

            cur = float(line)
            rmsq =    (sd ** 2 + arithM ** 2) * n
            n += 1
            # maybe `n`?
            arithM = (arithM * (n - 1) + cur) / n
            sd     =  sqrt(((rmsq + cur ** 2) / n) \
                           - arithM ** 2) * 1.0
            quadM  =   sqrt((rmsq + cur ** 2) / n)
            hM     =   n / ((1 / cur) + ((n - 1) / hM))
            print(f"    Number of values:	{n}",
                  f"    Standard deviation:	{sd:0.2f}",
                  f"    Arithmetic mean:	{arithM:0.2f}",
                  f"    Root mean square:	{quadM:0.2f}",
                  f"    Harmonic mean:	{hM:0.2f}",
                  sep='\n', end='\n\n')
    exit(0)


if __name__ == "__main__":
    if len(argv) != 5:
        if len(argv) == 2 and argv[1] == "-h":
            print("USAGE", "	./206neutrinos n a h sd", "", "DESCRIPTION",
                "	n	number of values",
                "	a	arithmetic mean",
                "	h	harmonic mean",
                "	sd	standard deviation", sep='\n')
            exit(0)
        else:
            print("invalid arguments (incorrect number)", file=stderr)
            exit(84)

    try:
        args = [float(_) for _ in argv[1:]]
        if any(_ < 0 for _ in args):
            print("invalid arguments (all must be positive)", file=stderr)
            exit(84)
        neutrinos(*args)
    except EOFError:
        exit(0)
    except BaseException as e:
        print("runtime error: ", e, file=stderr)
        exit(84)
