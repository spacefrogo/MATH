/*
** EPITECH PROJECT, 2018
** cipher
** File description:
** cipher
*/

#include "include/my.h"

int	get_length_of_matrix(char *message, char *key)
{
    int size = get_size_of_matrix(key);
    int length = strlen(message) / size;

    if (strlen(message) % size != 0)
        length++;
    else
        return length;
    return length;
}

int	get_size_of_matrix(char *string)
{
    int size = strlen(string);
    int length = sqrt(size);
    
    if (size < 10) {
        if (size != 1 && size != 4 && size != 9)
            length++;
    } else
        return (84);
    return length;
}

int	**transpose(int **key_matrix, char *key)
{
    int size = get_size_of_matrix(key);
    int **result = mem_alloc_int_array(size, size);
    int i = 0;
    int j = 0;

    while (i < size) {
        while (j < size) {
            result[i][j] = key_matrix[j][i];
            j++;
        }
        result[i][size] = '\0';
        j = 0;
        i++;
    }
    return (result);
}

float	**result_matrix(int **key_matrix, char *key)
{
    float d = determinate_matrix(key_matrix, key);
    int **result = transpose(key_matrix, key);
    int size = get_size_of_matrix(key);
    float       **final = mem_alloc_float_array(size, size);
    int i = 0;
    int j = 0;
    float rr = key_matrix[1][1] / d;

    while (i < size) {
        while (j < size) {
            final[i][j] = result[i][j] / d;
            j++;
        }
        final[i][size] = '\0';
        j = 0;
        i++;
    }
    return final;
}

void	my_print_float_array(float **arr, char *string)
{
    int i = 0;
    int j = 0;

    if (!arr)
        exit(84);
    printf("Key matrix:\n");
    while (i < get_size_of_matrix(string)) {
        while (j < get_size_of_matrix(string)) {
            printf("%.3f", arr[i][j]);
            if (j < get_size_of_matrix(string) - 1)
                printf("\t");
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
    printf("\nDecrypted message:\n");
}
