NAME			:= containers
SRCS			:= main.cpp
OBJS			:= $(SRCS:.cpp=.o)
HEADERS_DIR		:= ../
HEADERS_LIST	:=	enable_if.hpp \
					is_integral.hpp \
					iterator.hpp \
					iteratorTraits.hpp \
					randomAccessIterator.hpp \
					bstIterator.hpp \
					reverse_iterator.hpp \
					equal.hpp \
					lexicographical_compare.hpp \
					pair.hpp \
					vector.hpp \
					stack.hpp \
					binarySearchTree.hpp \
					map.hpp \
					node.hpp
HEADERFILES		:= $(addprefix $(HEADERS_DIR)/,$(HEADERS_LIST))
RM				= rm -rf
CC				= clang++
COMMON			=
CXXFLAGS		?= -Wall -Werror -Wextra -std=c++98 $(COMMON)
LDFLAGS			?= $(COMMON)
SANITIZE		= -g3 -fsanitize=address
FT				= -D NS=ft
STD				= -D NS=std

$(NAME):	$(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o:	%.cpp $(HEADERFILES)
	$(CC) -c $(CXXFLAGS) $< -o $@

all:	$(NAME)

std:	CXXFLAGS += $(STD)
std:	re

ft:		CXXFLAGS += $(FT)
ft:		re

debug:	COMMON += $(SANITIZE)
debug:	re

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re debug
