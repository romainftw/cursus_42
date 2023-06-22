SRCS    =   ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils_second.c
OBJS    =   ${SRCS:.c=.o}
RM      =   rm -f
CFLAGS  =   -Wall -Wextra -Werror
NAME    = libftprintf.a
LIB     = ft
all:    ${NAME}
.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:    ${OBJS}
	ar rc ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all