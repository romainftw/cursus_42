CLIENT = client.c

SRV	= serveur.c

OBJS = $(CLIENT:.c=.o)
OBJ = $(SRV:.c=.o)

RM		=	rm -f

SRC = serveur.c client.c

CFLAGS	=	-Wall -Wextra -Werror

LIB_PATH =  lib/ft_printf/libftprintf.a lib/gnl/libgnl.a lib/libft/libft.a

NAME_C = client

NAME_S = serveur

.c.o:	gcc ${CFLAGS} -c $< -o $@

$(NAME_C): $(OBJS)
	make -C lib/libft
	make -C lib/gnl
	make -C lib/ft_printf
	gcc ${CFLAGS} ${LIB_PATH} ${OBJS} -o ${NAME_C}

$(NAME_S): $(OBJ)
	make -C lib/libft
	make -C lib/gnl
	make -C lib/ft_printf
	gcc ${CFLAGS} ${LIB_PATH} ${OBJ} -o ${NAME_S}

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