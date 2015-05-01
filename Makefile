# change with $(GCC) or $(CLANG) depend system
CC = $(CLANG)

# change your includes
HEADER = includes/HEADER

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
	src/render/render_close.c \
	src/render/render_draw.c \
	src/render/render_draw_case.c \
	src/render/render_draw_player.c \
	src/render/render_draw_wall.c \
	src/render/render_init_.c \
	src/render/render_keyboard.c

# Don'y modify following
GCC = gcc
CLANG = clang
CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -C libft

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I glfw/include/ -I libft/includes -I includes/ -c $< -o $@

$(NAME): $(LIB) glfw $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) \
	-I glfw/include/ -I libft/ -I includes/ \
	-L glfw/src/ \
	-lglfw3 -framework Cocoa -framework OpenGL \
	-framework IOKit -framework CoreVideo

glfw:
	sh install.sh

rend:
	$(CC) $(CFLAGS) src/render/main_test.c libft/libft.a \
	-I glfw/include/ -I libft/ -L glfw/src/ \
	-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	git submodule deinit -f glfw
	rm -rf glfw
	rm -rf .gitmodules
	git rm --cached -f glfw
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re