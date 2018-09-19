LDFLAGS = -Wall -Werror -Wextra -lncurses

NAME= ft_retro

all:
	clang++ *.cpp $(LDFLAGS) -o $(NAME)

clean: 
	rm -f $(NAME)

re: clean all