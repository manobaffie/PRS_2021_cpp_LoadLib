NAME		=	a.out

LIBS		=	

CXXFLAGS	=	-Wall -Wextra -g3

SRC			=	src/main.cpp
				# lib/MapFunc/MapFunc.cpp 

OBJS		=	$(SRC:.cpp=.o)

CC			= g++

$(NAME): $(OBJS)	
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIBS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		clean fclean re all