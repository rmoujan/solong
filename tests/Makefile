NAME=so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC=so_long.c\
	get_next_line.c\
	get_next_line_utils.c\
	tools.c\
	checking_map.c\
	importing_map.c\
	operations.c\
	moves1.c\
	create_win.c\
	moves2.c\
	check_extensions.c 

OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

# $(NAME): ${OBJ}
# 	$(CC) $(OBJ) -o $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
		@${CC} -c ${CFLAGS} -I/usr/local/include $< -o $@

# %.o: %.c
# 		${CC} -c ${CFLAGS} $< -o $@

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
##Notes : that $< is patterned to match prerequisites and $@ matches the target