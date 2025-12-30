NAME = push_swap.a

AR = ar rcs

RM = rm -f

SRC =	algo_part1.c\
	algo_part2.c\
	fix_index.c\
	helper1.c\
	helper2.c\
	main.c\
	push_swap.c\
	push.c\
	revers_rotate.c\
	rotate.c\
	sorts.c\
	split.c\
	swap.c
	

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM)	$(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

