/*
** EPITECH PROJECT, 2018
** my
** File description:
** header file
*/

#ifndef _MY_H_
#define _MY_H_

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	small_function(int, int);
char	**mem_alloc_2d_array(int, int);
char	**fill(char const *, int, int);
void	info(void);
int	**get_key_matrix(char *);
int	get_size_of_matrix(char *);
void	my_print_key_array(int **, char *);
int	*string_to_ascii(char *);
int	**mem_alloc_int_array(int, int);
int	**get_key_matrix(char *);
int	get_length_of_matrix(char *, char *);
int	**transpose(int **, char *);
float	determinate_matrix(int **, char *);
float	**mem_alloc_float_array(int, int);
float	**result_matrix(int **, char *);
void	calculate_matrix(int **, int **, int, int);
int	**get_message_matrix(char *, char *);
void	encryption(int **, char *, char *);
void	my_print_float_array(float **, char *);

#endif /* _MY_H_ */
