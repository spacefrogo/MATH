/*
** EPITECH PROJECT, 2018
** my
** File description:
** header file
*/

#ifndef _MY_H_
#define _MY_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	print_usage(void);
char	**string_to_double_array(char *);
void	my_print_array(char **);
char	**mem_alloc_2d_array(int, int);
int	get_sizeof_2d(char **);
char	*get_one_part(char *, int);
double	**ascii_to_double(char **);
char	**get_data(int);
int     control_sign(char **);
int	help_control(char **, int, int);

#endif /* _MY_H_ */
