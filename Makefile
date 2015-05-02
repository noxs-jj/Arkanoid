# change with $(GCC) or $(CLANG) depend system
CC = $(CLANG)

# change your includes
HEADER = includes/projet.h

# change binary name
NAME = Arkanoid

# add sources files
SRCS =	src/main.c \
		src/basic_functions.c \
		src/init_start.c \
		src/init_map.c \
		src/fill_map.c \
		src/get_level_file.c \
		src/move.c \
		src/game.c \
		src/run.c \
		src/collide.c \
		src/exit_free.c \
		src/render/render_close.c \
		src/render/render_draw.c \
		src/render/render_draw_case.c \
		src/render/render_draw_player.c \
		src/render/render_init.c \
		src/render/render_keyboard.c \
		src/render/render_score.c

# Don'y modify following
GCC = gcc
CLANG = clang
CFLAGS = -Wall -Werror -Wextra -w
LIB_GLFW = glfw/src/libglfw3.a
LIB = libft/libft.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB_GLFW):
	@echo "\t\tGLFW install START"
	git submodule init && git submodule update && cd glfw && cmake . && make
	@echo "\t\tGLFW install DONE"

$(LIB):
	make -C libft

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I glfw/include/ -I libft/includes -I includes/ -c $< -o $@

$(NAME):  $(LIB_GLFW) $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_GLFW) $(LIB) \
	-I glfw/include/ -I libft/ -I includes/ \
	-L glfw/src/ -lglfw3 -framework GLUT \
	-framework Cocoa -framework OpenGL \
	-framework IOKit -framework CoreVideo

glfw:
	git submodule init && git submodule update
	$(shell cd glfw && cmake . && make)

rend:
	$(CC) $(CFLAGS) src/render/main_test.c libft/libft.a \
	-I glfw/include/ -I libft/ -L glfw/src/ \
	-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

gclean:
	git submodule deinit -f glfw

re: fclean all

.PHONY: all clean fclean re
