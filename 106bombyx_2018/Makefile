##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c		\
		my_str_isnum.c	\
		help.c		\

NAME	=	106bombyx

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -I /include -lm -g -g3 -ggdb

clean:
		rm -f $(OBJ) *~

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
