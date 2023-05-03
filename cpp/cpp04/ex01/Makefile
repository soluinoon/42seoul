NAME = ex01
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRCS = Cat.cpp Dog.cpp Animal.cpp main.cpp WrongCat.cpp WrongAnimal.cpp \
	Brain.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Cat.hpp Dog.hpp Animal.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re