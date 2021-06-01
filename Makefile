NAME		=	a.out

LIBS		=	-ldl

CXXFLAGS	=	-Wall -Wextra -g3 -std=c++17 

SRC			=	src/main.cpp				\
				lib/math/graph/graph.cpp		\
				# lib/math/matrix.cpp			\
				# lib/JsonPars/JsonPars.cpp		\
				# lib/Log/ILog.cpp				\
				# lib/Thread/Thread.cpp			\
				# lib/MapFunc/MapFunc.cpp		\

OBJS		=	$(SRC:.cpp=.o)

CC			= c++

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIBS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		clean fclean re all