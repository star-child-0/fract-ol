FILES = main.c valid_args.c init.c which_fractal.c\
	error_msg.c hooks.c draw.c\
	mandelbrot.c julia.c\

LIBFT = libft/libft.a

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(FILES))

OBJECTS = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

NAME = fractol

all: lib $(NAME)

lib:
	make -sC libft

$(NAME): $(OBJECTS)
	@echo "Compiling fract-ol"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L minilibx-linux -lmlx -lXext -lX11 -lm $(LIBFT)
	@echo "Done"

clean:
	@echo "Cleaning"
	@make clean -sC libft
	@$(RM) $(OBJECTS)
	@echo "Done"

fclean: clean
	@echo "Removing"
	@make fclean -sC libft
	@$(RM) $(NAME) $(OBJECTS)
	@echo "Done"

re: fclean all

push:
	git add .
	git commit -m "make push update"
	git push
	
norm:
	norminette ./libft/
	norminette $(SRC)

.PHONY:	all clean fclean re push
.SILENT:
