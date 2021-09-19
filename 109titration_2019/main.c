/*
** EPITECH PROJECT, 2019
** transfer
** File description:
** functions for transfer
*/

#include "include/my.h"

double	**ascii_to_double(char **tmp)
{
    int lines = get_sizeof_2d(tmp);
    char	*part1 = malloc(sizeof(char) * 1024);
    char	*part2 = malloc(sizeof(char) * 1024);
    double	**dou = malloc(sizeof(double *) * (lines + 1));

    for (unsigned int i = 0; i < lines; i++) {
        dou[i] = malloc(sizeof(double) * 2);
        part1 = get_one_part(tmp[i], 0);
        part2 = get_one_part(tmp[i], 1);
        dou[i][0] = atof(part1);
        dou[i][1] = atof(part2);
    }
    free(part1);
    free(part2);
    return dou;
}

char	**get_data(int fd)
{
    char *buf = malloc(sizeof(char) * 1024);
    unsigned int i = 0;

    read(fd, buf, 1024);
    while (buf[i] != '\0') {
        if ((buf[i] >= '0' && buf[i] <= '9') || buf[i] == ';' || \
            buf[i] == '.' || buf[i] == '-' || buf[i] == '\n') {
            i++;
        }
        else {
            free(buf);
            return NULL;
        }
    }
    char **arr = string_to_double_array(buf);
    free(buf);
    if (get_sizeof_2d(arr) == 0)
        return NULL;
    return arr;
}

int	main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    int fd = open(av[1], O_RDONLY);
    if (strcmp(av[1], "-h") == 0 && strlen(av[1]) == 2) {
        print_usage();
        return (0);
    }
    if (fd == -1)
        return 84;
    char **arr = get_data(fd);
    if (arr == NULL)
        return 84;
    return 0;
}
