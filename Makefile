##
## EPITECH PROJECT, 2020
## makefile for print
## File description:
## Makefile
##

SRC	=	sources/graphical_main.c	\
		sources/sprites_display.c	\
		sources/texture_calc.c	\
		sources/time_shif_control.c	\
		sources/window_control.c	\
		sources/time_shift.c	\
		sources/sprite_creat.c	\
		sources/assets_creation.c	\
		sources/assets_behavior.c	\
		sources/central_functions.c	\
		sources/ammo.c	\
		sources/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -Wall -Wextra -I./include

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
			rm $(NAME)

re:    	fclean	\
		all