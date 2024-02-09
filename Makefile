NAME = push_swap
CC = cc -g
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC =	cost.c \
		free.c \
		manipulate_lists.c \
		prepare_for_big_sort.c \
		push_swap.c \
		push.c \
		reverse.c \
		rotate.c \
		sort.c \
		swap.c \
		helper_functions.c \
		error_check.c \
		prep_for_push_to_a.c \
		split.c \
		find_cheapest.c

OBJ = ${SRC:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ} ${NAME}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re

