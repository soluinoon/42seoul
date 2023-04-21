NAME = zombie
CXX = clang++ 
CXXFLAGS = -Wall -Wextra -Werror
SRCS = newZombie.cpp main.cpp randomChump.cpp Zombie.cpp
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