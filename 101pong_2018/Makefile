##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	pong.c

NAME	=	101pong

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I ./include -lm -g -g3 -ggdb

clean:
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
