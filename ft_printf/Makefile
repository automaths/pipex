SRCS			=	attributes.c conversions.c ft_printf.c utils_bis.c \
					utils_ter.c utils.c conversions_bis.c \

OBJS			= 	$(SRCS:.c=.o) 

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror -I.

NAME			= 	libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
