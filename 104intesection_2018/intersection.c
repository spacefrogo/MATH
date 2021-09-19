/*
** EPITECH PROJECT, 2018
** intersection
** File description:
** project
*/

#include "./include/my.h"

int	check_is_num(char *av)
{
    int i = 0;

    while (av[i] != '\0') {
        if (av[0] == '-')
            i++;
        if (!((av[i] >= '0' && av[i] <= '9') || av[i] == '.'))
            exit(84);
        i++;
    }
    return (0);
}

void	check_num(char **av)
{
    int i;
    int j;

    for (i = 1; i < 9; i++) {
        check_is_num(av[i]);
    }
}

void	print_usage(void)
{
    printf("USAGE");
    printf("\n    ./104intersection opt xp yp zp xv yv zv p");
    printf("\n\nDESCRIPTION");
    printf("\n    opt   \t   surface option: 1 for a sphere, ");
    printf("2 for a cylinder, 3 for a cone");
    printf("\n    (xp, yp, zp)   coordinates of a point by which the light");
    printf(" ray passes through");
    printf("\n    (xv, yv, zv)   coordinates of a vector parallel to");
    printf("the light ray");
    printf("\n    p   \t   parameter: radius of the sphere, radius of ");
    printf("the cylinder, or");
    printf("\n    \t           angle formed by the cone and the Z-axis\n");
}

int	main(int ac, char **av)
{
    if (ac == 1)
        exit(84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0' && ac == 2) {
        print_usage();
        return (0);
    }
    if (ac != 9)
        exit(84);
    check_num(av);
    calculate(av);
    return (0);
}
