/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "include/my.h"

int	first_calc(int ac, char **av)
{
    if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
        return (84);
    double	x1 = atof(av[1]);
    double	k = atof(av[2]);
    int i = 1;

    if (k < 1 || k > 4)
        return (84);
    printf("%d %.2f\n", i, x1);
    for (; i < 100; i++) {
        x1 = k * x1 * ((1000 - x1) / 1000);
        printf("%d %.2f\n", i + 1, x1);
    }
    return (0);
}

int	bombyx(int ac, char **av)
{
    if (ac != 2 && ac != 3 && ac != 4)
        return (84);
    if (ac == 2) {
        if (strcmp(av[1], "-h") == 0)
            print_dash_h();
        else
            return (84);
    }
    if (ac == 3) {
        if (first_calc(ac, av) == 0)
            return (0);
        else
            return (84);
    }
    if (ac == 4) {
        return (0);
    }
}

int	main(int ac, char **av)
{
    int i = bombyx(ac, av);

    return i;
}
