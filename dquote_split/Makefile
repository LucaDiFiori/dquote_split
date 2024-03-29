NAME = dquotesplit

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

SRCS = dquotesplit_utils.c dquotesplit.c minilib.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)
		
re: 	fclean all