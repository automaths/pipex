SRCS			=	./pipex.c ./parsing.c ./utils.c ./parenting.c ./gadgets.c ./freeing.c

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	./libftprintf.a ./libft.a

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror -I./incs 

NAME			= 	pipex

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)
				$(RM) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus