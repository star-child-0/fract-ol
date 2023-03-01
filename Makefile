FILES = main.c valid_args.c init.c error_msg.c hooks.c equation.c\

LIBFT = libft/libft.a

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(FILES))

OBJECTS = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

NAME = fractol

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	make all -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L minilibx-linux -lmlx -lXext -lX11 -lm $(LIBFT)
	clear

clean:
	make clean -C libft
	make clean -C minilibx-linux
	$(RM) $(OBJECTS)
	clear

fclean: clean
	make fclean -C libft
	$(RM) $(NAME) $(OBJECTS)
	clear

re: fclean all

push:
	git add .
	git commit -m "make push update"
	git push

.PHONY:	all clean fclean re
.SILENT: