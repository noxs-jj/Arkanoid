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

# Don'y modify following
GCC = gcc
CLANG = clang
CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -C libft

$(MLX):
	make -C minilibx

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB) glfw $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

glfw:
	sh install.sh

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