# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:03:32 by cgouiame          #+#    #+#              #
#    Updated: 2023/12/13 17:05:44 by cgouiame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

INC = Animal.hpp Cat.hpp Dog.hpp WrongCat.hpp WrongAnimal.hpp

SRC		=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp

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
