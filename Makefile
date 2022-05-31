SRCS			=	./srcs/pipex.c

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	./srcs/libftprintf.a

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror -I./incs

NAME			= 	pipex

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus