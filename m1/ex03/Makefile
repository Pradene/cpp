SRCS		= HumanA.cpp \
			HumanB.cpp \
			Weapon.cpp \
			main.cpp

OBJS		= $(SRCS:.cpp=.o)

COMPILER	= c++

CFLAGS		= -std=c++98 -Wall -Wextra -Werror -g

NAME		= Violence

all:	$(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: re fclean clean all