##
## EPITECH PROJECT, 2018
## 104_intersection
## File description:
## working on it
##

NAME    =	104intersection

SRC     =	$(wildcard *.c)

CC      =	gcc

H	=	./include/my.h

all:		$(NAME)

$(NAME):	
		$(CC) $(SRC) $(H) -o $(NAME) -lm

clean:
		rm -f *~
		rm -f *gcno
		rm -f *gcda
		rm -f *gch
		rm -f *o
		rm -f ./tests/*gcda
		rm -f ./tests/*o
		rm -f ./tests/*gcno
		rm -f ./tests/*~
		rm -f *.out
		rm -f ./tests/*units

fclean:         clean
		rm -f $(NAME)

re:             fclean all

tests_run:
		make -C ./tests/
		./tests/units

.PHONY:         all clean fclean re
