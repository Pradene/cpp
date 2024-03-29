SRCSDIR		= srcs
OBJSDIR		= objs

FILES		= Bureaucrat.cpp \
			main.cpp

OBJS		= $(addprefix $(OBJSDIR)/, $(FILES:.cpp=.o))
SRCS		= $(addprefix $(SRCSDIR)/, $(FILES))

CXX			= c++

CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -g

NAME		= Bureaucrat

all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.cpp
	mkdir -p $(OBJSDIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJSDIR)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: re fclean clean all