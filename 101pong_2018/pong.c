/*
** EPITECH PROJECT, 2018
** pong
** File description:
** pong
*/

#include "my.h"


int	main(int ac, char **av)
{
    float x0;
    float y0;
    float z0;
    float x1;
    float y1;
    float z1;
    float n;
    float angle;
    float dist;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        printf("USAGE\n");
        printf("\t./101pong x0 y0 z0 x1 y1 z1 n\n");
        printf("\n");
        printf("DESCRIPTION\n");
        printf("\tx0	ball abscissa at time t - 1\n");
        printf("\ty0	ball ordinate at time t - 1\n");
        printf("\tz0	ball altitude at time t - 1\n");
        printf("\tx1	ball abscissa at time t\n");
        printf("\ty1	ball ordinate at time t\n");
        printf("\tz1	ball altitude at time t\n");
        printf("\tn	time shift (greater than or equal to zero, integer)\n");
        return (0);
    }
    if (ac != 8 && (ac != 2 && av[1] != "-h"))
        return (84);
    if (ac == 8) {
        x0 = atof(av[1]);
        y0 = atof(av[2]);
        z0 = atof(av[3]);
        x1 = atof(av[4]);
        y1 = atof(av[5]);
        z1 = atof(av[6]);
        n = atof(av[7]);
        dist = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2) + pow(z1 - z0, 2));
        printf("The velocity vector of the ball is:\n");
        printf("(%.2f, %.2f, %.2f)\n", x1 - x0, y1 - y0, z1 - z0);
        printf("At time t + %.0f, ball coordinates will be:\n", n);
        printf("(%.2f, %.2f", x1 + n * (x1 - x0), y1 + n * (y1 - y0));
        printf(", %.2f)\n", z1 + n * (z1 - z0));
        angle = (180 * (acos((z1 - z0) / dist) / PI)) - 90;
        if (angle < 0)
            angle = angle * (-1);
        if (-z1 / (z1 - z0) >= 0 && x1 + n * (x1 - x0) != 0)
            printf("The incidence angle is:\n%.2f degrees\n", angle);
        else
            printf("The ball won't reach the bat.\n");
        return (0);
    }
}
