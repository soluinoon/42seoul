NAME = zombie
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re