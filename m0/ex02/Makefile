SRCS		= Account.cpp \
			tests.cpp

OBJS		= $(SRCS:.cpp=.o)

COMPILER	= c++

CFLAGS		= -std=c++98 -Wall -Wextra -Werror -g

NAME		= Account

all:	$(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: re fclean clean all