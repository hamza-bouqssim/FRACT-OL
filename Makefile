SRC = shapes_drawing.c functions.c main.c calculations.c color_palette.c charts.c
OBJ = ${SRC:.c=.o}
GCC = gcc -Wall -Wextra -Werror -Ofast
NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) 
	$(GCC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractol.h
	$(GCC) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re