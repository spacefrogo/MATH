##
## EPITECH PROJECT, 2019
## cpp_rush3_2019
## File description:
## automated desc ftw
##

NAME = 201yams
SRC = $(shell find ./app ./src -name '*.hs')

$(NAME): all

all: $(SRC)
	stack install 201yams:exe:201yams --local-bin-path '.'

tests_run:
	stack install 201yams:test:201yams-test --local-bin-path '.'

clean: fclean

fclean: ./.stack-work
	rm -rf .stack-work tags TAGS

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: clean re
