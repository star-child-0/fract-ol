FILES = ft_draw.c ft_key_hooks.c ft_main.c passes.c \

LIBFT = libft/libft.a

OBJECTS = $(FILES:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = fractol

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libft
	make all -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L minilibx-linux -lmlx -lXext -lX11 -lm $(LIBFT)
	clear

clean:
	make clean -C ./libft
	make clean -C ./minilibx-linux
	$(RM) $(OBJECTS)
	clear

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) $(OBJECTS)
	clear

re: fclean all

push:
	git add .
	git commit -m "make push update"
	git push

.PHONY:	all clean fclean re
.SILENT:
