#!/usr/bin/env python3
##
## EPITECH PROJECT, 2018
## 102architect_2018
## File description:
## main file for 102architect
##

from itertools import product, starmap
from math import fsum, radians as r, sin, cos
from operator import mul
from typing import List
import sys

import user


class Coords:
    def __init__(self, x: float, y: float):
        self.vector = [ [float(x)], [float(y)], [1] ]
        self.old = ( int(x), int(y) )
        self.ident = [ [1., 0., 0.],
                       [0., 1., 0.],
                       [0., 0., 1.] ]

    @staticmethod
    def det(matrix: List[List[float]], mul):
        width = len(matrix)
        if width == 1:
            return mul * matrix[0][0]
        sign = True
        sum = 0
        for i in range(width):
            m = []
            for j in range(1, width):
                m.append([matrix[j][k] for k in range(width) if k != i])
            sign = not sign
            sum += mul * det(m, [-1 if sign is True else 1] * matrix[0][i])
        return sum

    @staticmethod
    def matmul(m_a: List[List[float]],
               m_b: List[List[float]]) -> List[List[float]]:
        """Return product of an MxP matrix A with an PxN matrix B."""
        cols, rows = len(m_b[0]), len(m_b)
        res_rows = range(len(m_a))
        res = [[0] * cols for _ in res_rows]
        for i in res_rows:
            for j, k in product(range(cols), range(rows)):
                res[i][j] = fsum([res[i][j], m_a[i][k] * m_b[k][j]])
        return res

    def translate(self, x: float, y: float):
        """Translate horizontally and vertically"""
        trident = [ [1, 0, float(x)],
                    [0, 1, float(y)],
                    [0, 0, 1       ] ]
        self.ident = self.matmul(trident, self.ident)
        print("Translation along vector ({0}, {1})".format(int(x), int(y)))
        return self

    def scale(self, x: float, y: float):
        """Scale horizontally and vertically"""
        scident = [ [float(x), 0       , 0],
                    [0,        float(y), 0],
                    [0,        0       , 1]]
        self.ident = self.matmul(scident, self.ident)
        print("Scaling by factors {0} and {1}".format(int(x), int(y)))
        return self

    def rotate(self, angle: float):
        """Rotate around (0, 0) in degrees"""
        roident = [ [cos(r(angle)), -sin(r(angle)), 0],
                    [sin(r(angle)),  cos(r(angle)), 0],
                    [0,             0,              1] ]
        self.ident = self.matmul(roident, self.ident)
        print("Rotation by a {} degree angle".format(int(angle)))
        return self

    def reflect(self, angle: float):
        """Rotation, reflection over the X axis, then rotation back
        to previous state
        """
        reident = [ [cos(r(2 * angle)),  sin(r(2 * angle)), 0],
                    [sin(r(2 * angle)), -cos(r(2 * angle)), 0],
                    [0,                  0,                 1] ]
        self.ident = self.matmul(reident, self.ident)
        print("Reflection over an axis with an inclination angle of {} degrees"
                .format(int(angle)))
        return self

    @staticmethod
    def mul(matrix: List[List[float]], vector: List[float]) -> List[float]:
        return [sum(starmap(mul, zip(vector, col))) for col in zip(*matrix)]

    # different implementation
    # def mul(ident, vector):
    #     arr = []
    #     for col in matrix:
    #         arr.append(fsum(starmap(mul, zip(vector, col))))
    #     return arr
    #
    # other implementation, same functionality (with lazy evaluation)
    # def mul(ident, vector):
    #     for col in indent:
    #         yield fsum(starmap(mul, zip(vector, col)))


def fill(argv: List[str]):
    coords = Coords(float(argv[1]), float(argv[2]))
    needed_args = flags = 0

    for i in argv:
        if i == '-t' or i == '-z':
            needed_args += 2
            flags += 1
        elif i == '-r' or i == '-s':
            needed_args += 1
            flags += 1
    if flags + needed_args != len(argv) - 3:
        user.errb("Incorrect arguments:")
    return coords


def solve(coords: Coords, argv):
    ai = iter(argv)
    for _ in ai:
        if _ == '-t':
            coords.translate(float(next(ai)), float(next(ai)))
        elif _ == '-z':
            coords.scale(float(next(ai)), float(next(ai)))
        elif _ == '-r':
            coords.rotate(float(next(ai)))
        elif _ == '-s':
            coords.reflect(float(next(ai)))


if __name__ == "__main__":
    user.check(sys.argv)
    try:
        coords = fill(sys.argv)
        solve(coords, sys.argv)
    except (IndexError, StopIteration):
        user.errb("Not enough arguments")
    except ValueError:
        user.errb("Invalid coordinates")
    user.print_res(coords)
