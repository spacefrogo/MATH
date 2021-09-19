/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "include/my.h"

int	**get_message_matrix(char *message, char *key)
{
    int size = get_size_of_matrix(key);
    int length = get_length_of_matrix(message, key);
    if (size == 84)
        exit(84);
    int **matrix = mem_alloc_int_array(length, size);
    int	*int_array = string_to_ascii(message);
    int i = 0;
    int j = 0;
    int k = 0;

    while (int_array[k] != '\0') {
        while (j < size) {
            matrix[i][j] = int_array[k];
            j++;
            k++;
        }
        matrix[i][size] = '\0';
        j = 0;
        i++;
    }
    return (matrix);
}

int	**get_key_matrix(char *key)
{
    int size = get_size_of_matrix(key);
    if (size == 84)
        exit(84);
    int **matrix = mem_alloc_int_array(size, size);
    int *int_array = string_to_ascii(key);
    int i = 0;
    int j = 0;
    int k = 0;

    while (int_array[k] != '\0') {
        while (j < size) {
            matrix[i][j] = int_array[k];
            j++;
            k++;
        }
        matrix[i][size] = '\0';
        j = 0;
        i++;
    }
    return matrix;
}

void	calculate_matrix(int **m_arr, int **k_arr, int r, int c)
{
    int i;
    int j;
    int k;
    int s = 0;
    int res;

    printf("Encrypted message:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res = 0;
            for (k = 0; k < c; k++)
                res = res + m_arr[i][k] * k_arr[k][j];
            s++;
            printf("%d", res);
            if (s < r * c)
                printf(" ");
        }
    }
}

int	main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        info();
        return (0);
    }
    if (ac != 4)
        return (84);
    char *message = av[1];
    char *key = av[2];
    int **key_matrix = get_key_matrix(key);
    int r = determinate_matrix(key_matrix, key);
    float **final = result_matrix(key_matrix, key);

    if (av[3][0] == '0') {
        encryption(key_matrix, key, message);
        return (0);
    } else if (av[3][0] == '1') {
        my_print_float_array(final, key);
        return (0);
    } else
        return (84);
}
