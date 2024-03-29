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
			
bonus:			$(OBJS_BONUS)
				@make -C ./ft_printf
				@make -C ./libft
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS_BONUS) $(LIBS)

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus