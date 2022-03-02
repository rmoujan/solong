NAME=so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
#MLX_FLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
#MLX_HEADER = /usr/local/include
SRC=so_long.c\
	get_next_line.c\
	get_next_line_utils.c\
	tools.c

OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
		${CC} -c ${CFLAGS} $< -o $@

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all