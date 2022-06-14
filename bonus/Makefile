SRCS			=	./pipex.c \
					./parsing.c \
					./utils.c \
					./parenting.c \
					./gadgets.c \
					./freeing.c

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	-L ./ft_printf -lftprintf -L ./libft -lft

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror

NAME			= 	pipex

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C ./ft_printf
				@make -C ./libft
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re