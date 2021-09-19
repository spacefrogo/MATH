/*
** EPITECH PROJECT, 2018
** determinate
** File description:
** detereminate
*/

#include "include/my.h"

float	determinate_matrix(int **a, char *key)
{
    float r;

    if (strlen(key) > 9 || strlen(key) <= 0)
        exit(84);
    if (strlen(key) > 4 && strlen(key) <= 9)
        r = a[0][0] * a[1][1] * a[2][2] + a[1][0] * a[2][1] * a[0][3] + \
            a[0][1] * a[1][2] * a[2][0] - a[0][2] * a[1][1] * a[2][0] - \
            a[0][1] * a[1][0] * a[2][2] - a[0][0] * a[1][2] * a[2][1];
    else if (strlen(key) <= 4 && strlen(key) != 1)
        r = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else
        r = a[0][0];
    return r;
}
