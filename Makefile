NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = cc
ANIMATED = so_long_anime
Mand = Mandatory/so_long.c
SRCS = 	moves.c \
		resize.c \
		split.c \
		str_join.c \
		substr.c \
		utils.c \
		utils2.c
libftprintf = ft_printf/ft_printf_utils.c \
			ft_printf/ft_printf_utils2.c \
			ft_printf/ft_printf.c
SRCS_B = Bonus/so_long_bonus.c spawn_enemies.c
Man_OBJ = ${Mand:.c=.o}
OBJ = ${SRCS:.c=.o}
OBJ_B = ${SRCS_B:.c=.o}

printf_obj = ${libftprintf:.c=.o}

all: ${NAME}

$(NAME): $(OBJ) ${printf_obj} ${Man_OBJ}
	$(CC) $(OBJ) ${printf_obj} ${Man_OBJ}  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(ANIMATED): ${OBJ_B} $(OBJ) ${printf_obj} 
	$(CC) $(OBJ) ${printf_obj} ${OBJ_B} -lmlx -framework OpenGL -framework AppKit -o $(ANIMATED)

bonus : $(ANIMATED)
clean:
	rm -rf $(OBJ) ${printf_obj} ${Man_OBJ} ${OBJ_B}

fclean: clean
		rm -rf ${NAME} $(ANIMATED)

re: fclean all

.PHONY: all clean fclean bonus