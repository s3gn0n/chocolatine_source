##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile files.
##

SRC		=	$(shell echo src/*.c)

OBJ		=	$(SRC:.c=.o)

NAME		=	my_sokoban


all		:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses -lcsfml-audio

tests_run :
		gcc -o unit_tests src/essentials_functions.c tests/test.c --coverage -lcriterion
		./unit_tests

clean	:
	 	rm -fr $(OBJ)
		rm -fr src/*~

fclean	:	clean
		rm -fr $(NAME)

re	:	fclean all
