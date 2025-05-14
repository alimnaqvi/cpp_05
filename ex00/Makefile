NAME = ex00
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -MMD -MP

SRCS = main.cpp Bureaucrat.cpp
OBJ_DIR = temp_files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPENDS = $(OBJS:.o=.d)

all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp Makefile | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
