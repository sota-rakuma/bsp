CXX:=clang++
CXXFLAGS:=-std=c++98 -Wall -Wextra -Werror
NAME:=a.out
SRC:=main.cpp \
	Fixed.cpp \
	Point.cpp \
	bsp.cpp

OBJ_DIR:=obj
OBJ:=$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEP_DIR:=dep
DEP:=$(addprefix $(DEP_DIR)/, $(SRC:.cpp=.d))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp
	@if ! [ -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi
	@ if ! [ -d $(DEP_DIR) ]; then \
		mkdir -p $(DEP_DIR); \
	fi
	$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<
	@mv $(OBJ_DIR)/*.d $(DEP_DIR)/

clean:
	rm -fR $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
