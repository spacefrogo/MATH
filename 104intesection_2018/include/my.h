/*
** EPITECH PROJECT, 2018
** ushquri
** File description:
** 104_intersection
*/

#ifndef TEST_H_
#define TEST_H_

#define PI 3.14159226358979323846
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>

int     check_is_num(char *av);
void    check_num(char **av);
void    print_usage(void);
void    print_1(char **av, float a, float b);
void    print_2(char **av, float a, float b, float d);
int     do_sphere(char **av);
int     make_cone(float a, float b, float c, char **av);
int     do_cone(char **av);
void    calculate(char **av);
void    help_cylinder(float b, float a, char **av);
void    help_cylinder_part_two(float b, float a, char **av, float d);
void    display(char **av);
int     do_cylinder(char **av);

#endif /* TEST_H_ */
