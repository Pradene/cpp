SRCSDIR		= srcs
OBJSDIR		= objs

FILES		= main.cpp

OBJS		= $(addprefix $(OBJSDIR)/, $(FILES:.cpp=.o))
SRCS		= $(addprefix $(SRCSDIR)/, $(FILES))

CXX			= c++

CXXFLAGS	= -std=c++98
CXXFLAGS	+= -Wall
CXXFLAGS	+= -Wextra
CXXFLAGS	+= -Werror
CXXFLAGS	+= -I./includes
CXXFLAGS	+= -g

NAME		= exe

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