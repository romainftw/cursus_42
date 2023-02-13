SRCS    =   main.c \
			push_swap.c \
			push_swap_move.c \
			parsing.c \
			push_swap_lst.c \
			push_swap_lst_sec.c \
			push_swap_radx.c \
			push_swap_move_sec.c
			
OBJS = $(SRCS:.c=.o)

RM		=	rm -f

LIB		=	libpush_swap.a

CFLAGS	=	-Wall -Wextra -Werror

LIB_PATH =  -L /usr/local/lib/ -L./lib/libft -l ft -L./lib/ft_printf -l ftprintf -L./lib/gnl -l gnl -L. -l push_swap

NAME = push_swap

.c.o:	gcc ${CFLAGS} -I /usr/local/include/ -c $< -o $@

$(NAME): $(OBJS)
	make -C lib/libft
	make -C lib/gnl
	make -C lib/ft_printf
	ar crs $(LIB) $(OBJS)
	gcc ${CFLAGS} -I /usr/local/include/ ${LIB_PATH} -o ${NAME}

all: $(NAME)

clean:
	make clean -C lib/libft
	make clean -C lib/gnl
	make clean -C lib/ft_printf
	${RM} ${OBJS}

fclean:	clean
	make fclean -C lib/libft
	make fclean -C lib/gnl
	make fclean -C lib/ft_printf
	${RM} ${NAME} ${LIB}

re:	fclean all
.PHONY: all clean flcean re