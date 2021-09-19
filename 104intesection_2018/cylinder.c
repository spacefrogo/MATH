/*
** EPITECH PROJECT, 2018
** project
** File description:
** cylinder
*/

#include "./include/my.h"

void	help_cylinder(float b, float a, char **av)
{
    float t = -b / (2 * a);
    float x = atof(av[5]) * t + atof(av[2]);
    float y = atof(av[6]) * t + atof(av[3]);
    float z = atof(av[7]) * t + atof(av[4]);

    printf("1 intersection point: \n");
    printf("(%0.3f, %0.3f, %0.3f)\n", x, y, z);
}

void	help_cylinder_part_two(float b, float a, char **av, float d)
{
    float t = (-b + sqrt(d)) / (2 * a);
    float t2 = (-b - sqrt(d)) / (2 * a);
    float x = atof(av[5]) * t + atof(av[2]);
    float y = atof(av[6]) * t + atof(av[3]);
    float z = atof(av[7]) * t + atof(av[4]);
    float x2 = atof(av[5]) * t2 + atof(av[2]);
    float y2 = atof(av[6]) * t2 + atof(av[3]);
    float z2 = atof(av[7]) * t2 + atof(av[4]);

    printf("2 intersection points: \n");
    printf("(%0.3f, %0.3f, %0.3f)\n", x, y, z);
    printf("(%0.3f, %0.3f, %0.3f)\n", x2, y2, z2);
}

void	display(char **av)
{
    printf("Cylinder of radius %s\n", av[8]);
    printf("Line passing through the point (%s, %s, %s)", av[2], av[3], av[4]);
    printf(" and parallel to the vector");
    printf(" (%s, %s, %s)\n", av[5], av[6], av[7]);
}

int	do_cylinder(char **av)
{
    float a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2);
    float b = 2 * ((atof(av[5]) * atof(av[2])) + (atof(av[6]) * atof(av[3])));
    float c = pow(atof(av[2]), 2) + pow(atof(av[3]), 2) - pow(atof(av[8]), 2);
    float d = pow(b, 2) - (4 * a * c);

    display(av);
    if (a == 0 && b == 0 && c == 0) {
        printf("There is an infinite number of intersection points.\n");
        return (0);
    }
    if (d < 0) {
        printf("No intersection point.\n");
        return (0);
    } else if (d == 0) {
        help_cylinder(b, a, av);
        return (0);
    } else {
        help_cylinder_part_two(b, a, av, d);
        return (0);
    }
    return (0);
}
