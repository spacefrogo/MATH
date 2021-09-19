/*
** EPITECH PROJECT, 2018
** cone
** File description:
** 104_intersection
*/

#include "./include/my.h"

int	make_cone(float a, float b, float c, char **av)
{
    float  d = pow(b, 2) - (4 * a * c);

    if (a == 0 && b == 0 && c == 0) {
        printf("There is an infinite number of intersection points.\n");
        return (0);
    }
    if (d < 0)
        printf("No intersection point.\n");
    if (d == 0)
        print_1(av, a, b);
    if (d > 0)
        print_2(av, a, b, d);
    return (0);
}

int	do_cone(char **av)
{
    float a;
    float b;
    float c;
    float d;
    float angle;

    angle = (PI * 2 * atof(av[8])) / 180;
    a = pow(tan(angle), 2) * (pow(atof(av[5]), 2) + pow(atof(av[6]), 2)) - \
    pow(atof(av[7]), 2);
    b = pow(tan(angle), 2) * (2 * ((atof(av[5]) * atof(av[2])) + \
    (atof(av[6]) * atof(av[3])))) - (2 * (atof(av[7]) * atof(av[4])));
    c = pow(tan(angle), 2) * (pow(atof(av[2]), 2) + pow(atof(av[3]), 2)) - \
    (pow(atof(av[4]), 2));
    make_cone(a, b, c, av);
    return (0);
}

void	print_1(char **av, float a, float b)
{
    float t;
    float x;
    float y;
    float z;

    printf("1 intersection point:\n");
    t = -b / (2 * a);
    x = atof(av[5]) * t + atof(av[2]);
    y = atof(av[6]) * t + atof(av[3]);
    z = atof(av[7]) * t + atof(av[4]);
    printf("(%0.3f, %0.3f, %0.3f)\n", x, y, z);
}

void	print_2(char **av, float a, float b, float d)
{
    float t2;
    float x2;
    float y2;
    float z2;
    float t;
    float x;
    float y;
    float z;

    printf("2 intersection points:\n");
    t = (-b + sqrt(d)) / (2 * a);
    t2 = (-b - sqrt(d)) / (2 * a);
    x = atof(av[5]) * t + atof(av[2]);
    y = atof(av[6]) * t + atof(av[3]);
    z = atof(av[7]) * t + atof(av[4]);
    x2 = atof(av[5]) * t2 + atof(av[2]);
    y2 = atof(av[6]) * t2 + atof(av[3]);
    z2 = atof(av[7]) * t2 + atof(av[4]);
    printf("(%0.3f, %0.3f, %0.3f)\n", x, y, z);
    printf("(%0.3f, %0.3f, %0.3f)\n", x2, y2, z2);
}
