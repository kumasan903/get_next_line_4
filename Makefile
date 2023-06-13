NAME		= get_next_line
SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
TESTFLAGS	= -g -fsanitize=address -fsanitize=undefined

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

test	:	fclean $(OBJS)
	$(CC) $(CFLAGS) $(TESTFLAGS) main.c $(OBJS)
	./a.out
	$(RM) ./a.out

.PHONY	:	clean fclean re all test
