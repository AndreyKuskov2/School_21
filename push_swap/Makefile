NAME = push_swap

LIBFT = ./libft
LIBFT_NAME = ${LIBFT}/libft.a

HEADERS =	./includes/push_swap.h \
			./includes/command.h \
			./includes/doubly_list_utils.h \
			./includes/doubly_list.h \
			./includes/sort_utils.h \
			./includes/sort.h \

SRC = 	./src/push_swap.c \
		./src/errors.c \
		./src/doubly_list.c \
		./src/doubly_list_2.c \
		./src/command.c \
		./src/command_2.c \
		./src/sort.c \
		./src/sort_2.c \
		./src/sort_3.c \
		./src/utils.c \
		./src/utils_2.c \

OBJ = ${SRC:.c=.o}

GCC = gcc

GFLAGS = -Wall -Werror -Wextra -o

RM = rm -f

CD = cd

MAKE = make

.c.o:
	${GCC} ${GFLAGS} $@ -c $<

all: ${NAME}

${NAME}: ${OBJ} ${HEADERS}
	cd ${LIBFT} && ${MAKE}
	${GCC} ${OBJ} ${LIBFT_NAME} -o ${NAME}

bonus:

clean:
	${CD} ${LIBFT} && ${MAKE} clean
	${RM} ${OBJ}

fclean: clean
	${CD} ${LIBFT} && ${MAKE} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: 
	all bonus clean fclean re