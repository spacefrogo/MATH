/*
** EPITECH PROJECT, 2018
** sphere
** File description:
** 104_intersection
*/

#include "./include/my.h"

int	do_sphere(char **av)
{
    float a;
    float b;
    float c;
    float d;

    a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2) + pow(atof(av[7]), 2);
    b = 2 * ((atof(av[5]) * atof(av[2])) + (atof(av[6]) * \
    atof(av[3])) + (atof(av[7])) * atof(av[4]));
    c = pow(atof(av[2]), 2) + pow(atof(av[3]), 2) + \
    pow(atof(av[4]), 2) - pow(atof(av[8]), 2);
    d = pow(b, 2) - (4 * a * c);
    if (a == 0 && b == 0 && c == 0)
        printf("There is an infinite number of intersection points.");
    if (d < 0)
        printf("No intersection point.\n");
    if (d == 0)
        print_1(av, a, b);
    if (d > 0)
        print_2(av, a, b, d);
    return (0);
}

void	calculate(char **av)
{
    if (atof(av[1]) < 1 || atof(av[1]) > 3)
        exit(84);
    if (atof(av[1]) == 1) {
        printf("Sphere of radius %s\nLine passing", av[8]);
        printf(" through the point (%s, %s, %s) and", av[2], av[3], av[4]);
        printf(" parallel to the vector (%s, %s, %s)\n", av[5], av[6], av[7]);
        do_sphere(av);
    }
    if (atof(av[1]) == 2) {
        do_cylinder(av);
    }
    if (atof(av[1]) == 3) {
        printf("Cone with a %s degree angle\nLine passing", av[8]);
        printf(" through the point (%s, %s, %s) and", av[2], av[3], av[4]);
        printf(" parallel to the vector (%s, %s, %s)\n", av[5], av[6], av[7]);
        do_cone(av);
    }
}
