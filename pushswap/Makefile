SRCS    =   push_swap_utilities.c \
			push_swap_lst.c \
			main.c \
			push_swap.c \
			push_swap_move.c \
			
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