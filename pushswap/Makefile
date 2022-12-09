SRCS    =   push_swap.c/
			push_swap.h
OBJS    =   ${SRCS:.c=.o}
RM      =   rm -f
CFLAGS  =   -Wall -Wextra -Werror
NAME    = push_swap.a
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