SRCS			=	./pipex.c \
					./parsing.c \
					./utils.c \
					./parenting.c \
					./gadgets.c \
					./freeing.c \
					./get_next_line/get_next_line.c \
					./get_next_line/get_next_line_utils.c \
					./here_doc.c

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	./libft.a ./libftprintf.a

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror

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

.PHONY:			all clean fclean re