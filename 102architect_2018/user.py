#!/usr/bin/env python3
##
## EPITECH PROJECT, 2018
## 102architect_2018
## File description:
## user interactions
##

import sys
from typing import List


def errb(*args, **kwargs) -> None:
    print(*args, file=sys.stderr, **kwargs)
    exit(84)


def help() -> None:
    print("""USAGE
./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...

DESCRIPTION
x      abscissa of the original point
y      ordinate of the original point

transfo arg1 [arg2]
-t i j      translation along vector (i, j)
-z m n      scaling by factors m (x-axis) and n (y-axis)
-r d        rotation centered in O by a d degree angle
-s d        reflection over the axis passing through O with an inclination
            angle of d degrees""")
    exit(0)


def check(argv: List[str]) -> None:
    if len(argv) < 2:
        errb("Incorrect arguments. Try '-h'")
    if argv[1] == '-h':
        help()
    try:
        for arg in argv[1:]:
            if arg not in ['-t', '-z', '-r', '-s'] \
                    and float(arg) is None \
                    and int(arg) is None:
                errb("Invalid argument:", arg)
    except ValueError:
        errb("Invalid argument (non-numeral):", arg)


def fix(arr: List[float]) -> List[float]:
    for i in arr:
        if abs(round(i, 2)) < 0.004:
            yield 0.00
        else:
            yield round(i, 2)


def print_res(coords) -> None:
    for i in coords.ident:
        print("{0:.2f}\t{1:.2f}\t{2:.2f}".format(*fix(i)))
    coords.vector = coords.matmul(coords.ident, coords.vector)
    print("({:d}, {:d}) => ({:.2f}, {:.2f})".format(
        coords.old[0], coords.old[1],
        *fix(coords.vector[0]),
        *fix(coords.vector[1])))
