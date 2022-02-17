NAME		:= containers
SRCS		:= main.cpp map.cpp stack.cpp vector.cpp
OBJS		:= $(SRCS:.cpp=.o)
RM			= rm -rf
CC			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

$(NAME):	$(OBJS)
	$(CC) $^ -o $@

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
