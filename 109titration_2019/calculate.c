/*
** EPITECH PROJECT, 2019
** altin
** File description:
** altin
*/

#include "include/my.h"

char    *get_one_part(char *buf, int x)
{
    char        *tmp = malloc(sizeof(char) * 1024);
    unsigned int i = 0;
    unsigned int j = 0;

    if (x == 0) {
        while (buf[i] != '\0' && buf[i] != ';') {
            tmp[i] = buf[i];
            i++;
        }
    } else if (x == 1) {
        for (; buf[i] != ';'; i++);
        i++;
        for (; buf[i] != '\0'; i++, j++)
            tmp[j] = buf[i];
    } else {
        free(tmp);
        return NULL;
    }
    return tmp;
}
