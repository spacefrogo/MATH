/*
** EPITECH PROJECT, 2019
** hello
** File description:
** there
*/

#include "include/my.h"

void	print_dash_h(void)
{
    printf("USAGE\n\t./106bombyx n [k | i0 i1]\n\nDESCRIPTION\n\tn\t");
    printf("number of first generation individuals\n\tk\tgrowth rate");
    printf(" from 1 to 4\n\ti0\tinitial generation (included)\n\t");
    printf("i1\tfinal generation (included)\n");
}

int	get_result(double i, char **av)
{
    double      x1 = atof(av[1]);
    double      x2 = x1 * i * ((1000 - x1) / 1000);

    return pow((x2 / x1), (1 / (2 - 1)));
}

void	second_cndt(int i, int i0, double k, double x1)
{
    if (i >= i0)
        printf("%.2f %.2f\n", k, x1);
}
