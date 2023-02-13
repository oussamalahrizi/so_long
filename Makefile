NAME = so_long
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
san = -fsanitize=address -g3

printf_obj = ${libftprintf:.c=.o}

all: ${NAME}

$(NAME): $(OBJ) ${printf_obj} ${Man_OBJ}
	$(CC) $(OBJ)  ${printf_obj} ${Man_OBJ} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(ANIMATED): ${OBJ_B} $(OBJ) ${printf_obj} 
	$(CC) $(OBJ) $(san) ${printf_obj} ${OBJ_B} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(ANIMATED)

bonus : $(ANIMATED)
clean:
	rm -rf $(OBJ) ${printf_obj} ${Man_OBJ} ${OBJ_B}

fclean: clean
		rm -rf ${NAME} $(ANIMATED)

re: fclean all

.PHONY: all clean fclean bonus