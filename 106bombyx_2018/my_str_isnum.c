/*
** EPITECH PROJECT, 2018
** Valton
** File description:
** Garuci
*/

#include "include/my.h"

int	my_str_isnum(const char *str)
{
    for (int i = 0; str && str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
