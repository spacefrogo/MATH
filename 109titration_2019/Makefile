##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		help.c	\
		calculate.c	\
		control.c \

NAME	=	109titration

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -I /include -lm -g -g3 -ggdb

clean:
		rm -f $(OBJ) *~

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
