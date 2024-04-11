##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile files.
##

SRC		=	$(shell echo src/*.c)

OBJ		=	$(SRC:.c=.o)

NAME		=	my_sokoban

sources		=	src/essentials_functions.c	\
			src/maps_functions_part_a.c	\
			src/maps_functions_part_b.c	\
			src/none_boxe.c			\

tests		=	$(shell echo tests/*.c)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses

tests_run :
		gcc -o unit_tests $(sources) $(tests) --coverage -lcriterion -lncurses
		./unit_tests

clean	:
	 	rm -fr $(OBJ)
		rm -fr src/*~

fclean	:	clean
		rm -fr $(NAME)

re	:	fclean all
