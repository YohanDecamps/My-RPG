##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

SRC	=	src/main.c							\
		src/my_rpg.c						\
		src/system/get_usr_input.c			\
    	src/system/getenv.c					\
		src/system/get_mouse_pos.c			\
		src/handle_movement.c				\
		src/draw_map.c						\
		src/draw_ray_cast.c					\
		src/camera_movement.c				\
		src/display_framerate.c				\
		src/init_rpg_values.c				\
		src/init_rpg_visuals.c				\
		src/init_other_rpg_vars.c			\
		src/main_menu/draw_all_buttons.c	\
		src/main_menu/draw_button.c 		\
		src/main_menu/init_all_buttons.c 	\
		src/main_menu/init_button.c 		\
		src/main_menu/is_clicked.c 			\
		src/main_menu/is_hover.c 			\
		src/main_menu/main_menu.c 			\
		src/main_menu/update_all_buttons.c 	\
		src/main_menu/update_button.c

TESTS_SRC = ./tests/tests_rpg.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS += -Wall -Wextra -Wshadow -Wimplicit

LDFLAGS += -L./lib -lmy -lm -lcsfml-graphics -lcsfml-audio \
-lcsfml-window -lcsfml-system

CPPFLAGS += -I./include

DEBUGFLAGS = -ggdb3 -fsanitize=address

all:	$(NAME)
PHONY	+= all

lib:
	make -C lib
PHONY += lib

$(NAME):	$(OBJ) lib
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

debug: lib
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) $(DEBUGFLAGS)
PHONY += debug

clean:
	rm -f $(OBJ)
	make -C lib clean
	find -name "*.gc*" -delete
PHONY	+= clean

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests
	make -C lib fclean

PHONY	+= fclean

re:	fclean all
PHONY	+= re

run: $(OBJ) lib
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)
	./$(NAME)

compile_tests: lib
	gcc -o unit_tests $(filter-out src/main.c, $(SRC)) \
	$(TESTS_SRC) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) --coverage -lcriterion
PHONY += compile_tests

tests_run: compile_tests
	./unit_tests
PHONY	+= tests_run

test: tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY:	$(PHONY)
