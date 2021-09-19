/*
** EPITECH PROJECT, 2018
** info
** File description:
** 103cipher
*/

#include "include/my.h"

void	info(void)
{
    printf("USAGE");
    printf("\n\t./103cipher message key flag\n");
    printf("\nDESCRIPTION");
    printf("\n\tmessage\t\t");
    printf("a message, made of ASCII characters");
    printf("\n\tkey\t\t");
    printf("the encryption key, made of ASCII characters");
    printf("\n\tflag\t\t");
    printf("0 for the message to be encrypted,");
    printf(" 1 to be decrypted\n");
}

void	my_print_key_array(int **arr, char *string)
{
    int i = 0;
    int j = 0;

    if (!arr)
        exit(84);
    while (i < get_size_of_matrix(string)) {
        while (j < get_size_of_matrix(string)) {
            printf("%d", arr[i][j]);
            if (j < get_size_of_matrix(string) - 1)
                printf("\t");
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
}

int	**mem_alloc_int_array(int nb_rows, int nb_cols)
{
    int i = 0;
    int **arr = NULL;

    arr = malloc(sizeof(int *) * (nb_rows + 1));
    arr[i] = malloc(sizeof(int) * nb_cols + 1);
    while (i < nb_rows) {
        arr[i] = malloc(sizeof(int) * nb_cols + 1);
        i++;
    }
    arr[i] = NULL;
    return (arr);
}

int	*string_to_ascii(char *string)
{
    int size = sqrt(strlen(string)) + 1;
    int *int_array = malloc(sizeof(int) * strlen(string) * 3);
    int i = 0;

    while (string[i] != '\0') {
        int_array[i] = (int)string[i];
        i++;
    }
    int_array[i] = '\0';
    return int_array;
}

float	**mem_alloc_float_array(int nb_rows, int nb_cols)
{
    int i = 0;
    float **arr = NULL;

    arr = malloc(sizeof(float *) * (nb_rows + 1));
    arr[i] = malloc(sizeof(float) * nb_cols + 1);
    while (i < nb_rows) {
        arr[i] = malloc(sizeof(float) * nb_cols + 1);
        i++;
    }
    arr[i] = NULL;
    return (arr);
}
