NAME = zombie
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = zombieHorde.cpp Zombie.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Zombie.hpp

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