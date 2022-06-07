##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = src/main.c \
	  src/error_handling.c \
	  src/utils/utils_stack/add_to_stack.c \
	  src/utils/utils_stack/show_list.c \
	  src/utils/utils_file/file_to_array.c \
	  src/fill_info.c \
	  src/utils/utils_info_dragon/fill_struct_info.c \
	  src/utils/utils_info_dragon/info_coords.c \
	  src/utils/utils_info_dragon/info_misc.c \
	  src/utils/utils_info_dragon/show_info_dragon.c \
	  src/utils/utils_stack/free_stack.c \
	  src/display/main_display.c \
	  src/display/display_sprites.c \
	  src/utils/utils_framebuffer/framebuffer.c \
	  src/display/utils_draw.c \
	  src/utils/utils_framebuffer/put_pixel.c \
	  src/display/update_dragons.c \
	  src/display/collisions.c \
	  src/display/landing.c \
	  src/display/change_sprites.c \
	  src/utils/utils_event.c

OBJ = $(SRC:.c=.o)

NAME = my_radar

INCLUDE = include

LIB = lib/my

CFLAGS = -I$(INCLUDE) -Wall -Wextra -g

all: $(NAME)

make_lib:
		  make -C $(LIB)

$(NAME): make_lib $(OBJ)
		 gcc -g -o $(NAME) $(OBJ) -L$(LIB) -lmy -lm -lcsfml-graphics \
		 -lcsfml-system
		 rm -f $(OBJ)

clean:
	   make clean -C $(LIB)
	   rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: fclean all debug re clean tests_run make_lib $(NAME)
