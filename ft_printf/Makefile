NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

$(OBJ): $(SRC)
		$(CC) -I ./  $(CFLAGS) -c $(SRC)
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all