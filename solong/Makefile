SRCS		=	main.c
				

OBJS    	=   $(SRCS:.c=.o)

RM			=	rm -f

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror

NAME		=	so_long

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		make -C libft
		$(CC) $(FLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -L. libft/libft.a -o $(NAME)


all:		$(NAME)

clean:
		make clean -C libft
		$(RM) $(OBJS)

fclean:		clean
		make fclean -C libft
		$(RM) $(NAME)

re:		fclean all