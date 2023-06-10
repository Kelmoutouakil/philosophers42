CC=gcc
NAME=philo
CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g3
SRC = main.c mylibft.c utils.c init.c cheek.c philo.c


OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all