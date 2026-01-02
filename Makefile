NAME = push_swap

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = algo_part1.c \
      algo_part2.c \
      algo_part3.c \
      fix_index.c \
      free_it.c \
      helper1.c \
      helper2.c \
	  helper3.c\
      main.c \
      push_swap.c \
      push.c \
      revers_rotate.c \
      rotate.c \
      sorts.c \
      split.c \
      swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
