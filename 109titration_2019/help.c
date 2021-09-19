/*
** EPITECH PROJECT, 2019
** help
** File description:
** me
*/

#include "include/my.h"

void	print_usage(void)
{
    printf("USAGE\n\t./109titration file\n\nDESCRIPTION\n\tfile\ta csv file");
    printf(" containing \"vol;ph\" lines\n");
}

char	**string_to_double_array(char *buffer)
{
    char **map = mem_alloc_2d_array(strlen(buffer), strlen(buffer));
    int i = 0;
    int n = 0;
    int m = 0;

    while (buffer[i] != '\0') {
        while (buffer[i] == '\n') {
            map[n][m] = '\0';
            i++;
        }
        while (buffer[i] != '\n' && buffer[i] != '\0') {
            map[n][m] = buffer[i];
            i++;
            m++;
        }
        m = 0;
        n++;
    }
    map[n - 1] = NULL;
    return (map);
}

void	my_print_array(char **arr)
{
    int i = 0;

    while (arr[i] != NULL) {
        printf("%s\n", arr[i]);
        i++;
    }
}

char	**mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int i = 0;
    char **arr = NULL;

    arr = malloc(sizeof(char *) * (nb_rows + 1));
    arr[i] = malloc(sizeof(char) * nb_cols + 1);
    while (i < nb_rows) {
        arr[i] = malloc(sizeof(char) * nb_cols + 1);
        i++;
    }
    arr[i] = NULL;
    return arr;
}   

int	get_sizeof_2d(char **arr)
{
    int i = 0;

    while (arr[i] != NULL)
        i++;
    return i;
}
