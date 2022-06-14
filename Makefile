SRCS			=	./pipex.c \
					./parsing.c \
					./utils.c \
					./utils_bis.c \
					./utils_ter.c \
					./parenting.c \
					./freeing.c \
					./here_doc.c \
					
SRCS_BONUS		=	./pipex_bonus.c \
					./parsing.c \
					./utils.c \
					./utils_bis.c \
					./utils_ter.c \
					./parenting.c \
					./freeing.c \
					./here_doc.c \

OBJS			= 	$(SRCS:.c=.o)

OBJS_BONUS		= 	$(SRCS_BONUS:.c=.o)

LIBS			= 	./libft.a ./libftprintf.a

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror

NAME			= 	pipex

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)
				$(RM) $(OBJS)
			
bonus:			$(OBJS_BONUS)
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS_BONUS) $(LIBS)
				$(RM) $(OBJS_BONUS)

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus