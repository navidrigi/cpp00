CXX			=		c++
CXXFLAGS	=		-Wall -Wextra -Werror -std=c++98
SRC			=		Account.cpp tests.cpp
NAME		=		account

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

.PHONY: all clean re

clean:
	rm -f $(NAME)

re: clean all
