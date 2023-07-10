SRCS		= Fixed.cpp \
			main.cpp

OBJS		= $(SRCS:.cpp=.o)

COMPILER	= c++

CFLAGS		= -std=c++98 -Wall -Wextra -Werror -g

NAME		= Fixed

all:	$(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: re fclean clean all