CC=gcc
NAME=philo_bonus
CFLAGS=-Wall -Wextra -Werror #-fsanitize=thread -g3
SRC = main.c mylibft_bonus.c  init_bonus.c cheek_bonus.c philo_bonus.c


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