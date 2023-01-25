CLIENT = client.c

SRV	= serveur.c

OBJS = $(CLIENT:.c=.o)
OBJ = $(SRV:.c=.o)

RM		=	rm -f

LIB		=	libmini_talk.a

CFLAGS	=	-Wall -Wextra -Werror

LIB_PATH =  -L./lib/libft -l ft -L./lib/ft_printf -l ftprintf -L./lib/gnl -l gnl -L. -l mini_talk

NAME_C = client

NAME_S = serveur

.c.o:	gcc ${CFLAGS} -c $< -o $@

$(NAME_C): $(OBJS)
	make -C lib/libft
	make -C lib/gnl
	make -C lib/ft_printf
	ar crs $(LIB) $(OBJS)
	gcc ${CFLAGS} ${LIB_PATH} -o ${NAME_C}

$(NAME_S): $(OBJ)
	make -C lib/libft
	make -C lib/gnl
	make -C lib/ft_printf
	ar crs $(LIB) $(OBJ)
	gcc ${CFLAGS} ${LIB_PATH} -o ${NAME_S}

all: $(NAME_C) $(NAME_S)

clean:
	make clean -C lib/libft
	make clean -C lib/gnl
	make clean -C lib/ft_printf
	${RM} ${OBJS} ${OBJ}

fclean:	clean
	make fclean -C lib/libft
	make fclean -C lib/gnl
	make fclean -C lib/ft_printf
	${RM} ${NAME_C} $(NAME_S) ${LIB}

re:	fclean all
.PHONY: all clean flcean re