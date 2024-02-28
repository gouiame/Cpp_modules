NAME = Base

INC = Base.hpp

SRC		=	main.cpp Base.cpp

CC 		= c++ -std=c++98

FLAGS	= -Wall -Wextra -Werror

OBJS 	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
		$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all