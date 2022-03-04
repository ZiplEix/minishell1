##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## makefile
##

SCR	=	main.c	\
		$(wildcard lib/*.c)	\
		$(wildcard src/code/*.c)	\
		$(wildcard src/error/*.c)	\
		$(wildcard src/exit/*.c)	\
		$(wildcard src/path/*.c)	\
		$(wildcard src/env/*.c)	\
		$(wildcard src/cd/*.c)	\
		$(wildcard src/binary/*.c)

OBJ	=	$(SCR:.c=.o)

CFLAGS	=	-I ../include -g3

NAME	=	mysh

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f vgcore*

fclean: clean
	rm -f $(NAME)
	rm -f vgcore*

re: fclean all

.PHONY	:	all	clean	fclean	re
