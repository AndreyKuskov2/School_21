NAME	= libftprintf.a

HEADER 	= ft_printf.h

MAN_SOR	=	ft_printf.c \
			ft_printf_utils_1.c \
			ft_printf_u.c \
			ft_printf_p.c \
			ft_printf_func.c \
			ft_printf_di.c \


MAN_OBJS	= ${MAN_SOR:.c=.o}

GCC		= gcc -Wall -Wextra -Werror

AR 		= ar -rcs

RM 		= rm -f

.c.o:
		${GCC} -c $< -o ${<:.c=.o} -I${HEADER}

${NAME}:	${MAN_OBJS} ${HEADER}
		${AR} ${NAME} ${MAN_OBJS}

all: ${NAME} 

bonus:		
		@make MAN_OBJS="$(BON_OBJS)" all

clean:
		${RM} ${MAN_OBJS} ${BON_OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all bonus

.PHONY: bonus all clean fclean re
