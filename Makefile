NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c utils.c parsing/parsing.c parsing/split.c stack/stack_init.c stack/stack_utils.c stack/array_utils.c \
		operations/op_push.c operations/op_rev_rotate.c operations/op_rotate.c operations/op_swap.c \
		sort/sort_radix.c sort/sort_small.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
