/*
** EPITECH PROJECT, 2019
** EPITECH
** File description:
** 2019
*/

#include "include/my.h"

int     control_sign(char **str)
{
    int count = 0;

    for (int i = 0; str[i] != NULL; i++) {
	if (help_control(str, i, count) == 84)
	    return (84);
    }
    return (0);
}

int	help_control(char **str, int i, int count)
{
    for (int j = 0; str[i][j] != '\0'; j++) {
	if (str[i][j] == ';')
	    count++;
    }
    if (count > 1)
	return 84;
}

double **second_derivative(double **deriv, int line)

{
    double **second_derivative;
    
    second_derivative = malloc(sizeof(double *) * (line - 3));
    if (second_derivative == NULL)
	return (NULL);
    
    help_second(second_derivative, line, deriv);
    return (second_derivative);
}

void    help_second(double **second_derivative, int line, double **deriv)
{
    int i = 0;
    int j = 1;

    while (i < line - 4) {
        second_derivative[i] = malloc(sizeof(double) * 2);
        if (second_derivative[i] == NULL)
            return;
        second_derivative[i][0] = deriv[j][0];
        second_derivative[i][1] = (deriv[j + 1][1] - deriv[j - 1][1]) /
	    (deriv[j + 1][0] - deriv[j - 1][0]);
        i++;
        j++;
    }
}
