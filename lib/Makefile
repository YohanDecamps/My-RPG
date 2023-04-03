##
## EPITECH PROJECT, 2023
## mylib
## File description:
## Make config file
##

SRC =	src/my_strlen.c				\
		src/analyse_event.c			\
		src/create_window.c			\
		src/create_text.c			\
		src/create_sprite.c

OBJ =	$(SRC:.c=.o)

CPPFLAGS	=	-I./include

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../include
	cp -r include ../include
	make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
