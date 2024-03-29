SRCS		= megaphone.cpp

OBJS		= $(SRCS:.cpp=.o)

COMPILER	= c++

CFLAGS		= -std=c++98 -Wall -Wextra -Werror

NAME		= megaphone

all:	$(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: re fclean clean all