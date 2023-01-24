SRCS		=	main.c \
				solong_parsing.c \
				solong_map.c \
				so_long_map_pars.c \
				so_long_check_way.c \
				so_long_graphic.c \
				solong_util.c

OBJS = $(SRCS:.c=.o)

RM		=	rm -f

LIB		=	libso_long.a

CFLAGS	=	-Wall -Wextra -Werror

FRAMEWORK	= -framework OpenGl -framework AppKit

LIB_PATH = -lmlx -L /usr/local/lib/ -L./lib/libft -l ft -L./lib/ft_printf -l ftprintf -L./lib/gnl -l gnl -L. -l so_long

NAME = so_long

.c.o:	gcc ${CFLAGS} -I /usr/local/include/ -c $< -o $@

$(NAME): $(OBJS)
	make -C lib/libft
	make -C lib/gnl
	make -C lib/ft_printf
	ar crs $(LIB) $(OBJS)
	gcc ${CFLAGS} -I /usr/local/include/ ${FRAMEWORK} ${LIB_PATH} -o ${NAME}

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