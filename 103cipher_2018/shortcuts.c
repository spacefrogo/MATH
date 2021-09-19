/*
** EPITECH PROJECT, 2018
** short
** File description:
** cut
*/

#include "include/my.h"

void	encryption(int **key_matrix, char *key, char *message)
{
    int row = get_length_of_matrix(message, key);
    int col = get_size_of_matrix(key);
    int **message_matrix = get_message_matrix(message, key);

    printf("Key matrix:\n");
    my_print_key_array(key_matrix, key);
    printf("\n");
    calculate_matrix(message_matrix, key_matrix, row, col);
    printf("\n");
}

void	small_function(int j, int size)
{
    if (j < size - 1)
        printf("\t");
}
