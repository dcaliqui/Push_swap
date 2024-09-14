

CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = intit_stack.c \
	main.c \
	utils.c \
	valitation.c \
	free_stack.c \
	operations.c \
	utils2.c \
	utils_list.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all

