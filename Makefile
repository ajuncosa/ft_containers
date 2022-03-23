NAME		:= containers
SRCS		:= main.cpp
OBJS		:= $(SRCS:.cpp=.o)
HEADERFILES	:= enable_if.hpp is_integral.hpp iterator.hpp iteratorTraits.hpp reverse_iterator.hpp equal.hpp lexicographical_compare.hpp pair.hpp vector.hpp stack.hpp map.hpp
RM			= rm -rf
CC			= clang++
COMMON		=
CXXFLAGS	?= -Wall -Werror -Wextra -std=c++98 $(COMMON)
LDFLAGS		?= $(COMMON)
SANITIZE	= -g3 -fsanitize=address

$(NAME):	$(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o:	%.cpp $(HEADERFILES)
	$(CC) -c $(CXXFLAGS) $< -o $@

all:	$(NAME)

debug:	COMMON += $(SANITIZE)
debug:	re

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re debug
