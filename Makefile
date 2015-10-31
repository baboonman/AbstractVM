CC= g++
FLAGS= -Wall -Wextra -Werror
NAME= avm

SRC= main.cpp

OBJ= $(SRC:.cpp=.o)

.PHONY: all clean fclean re
.SILENT:

all:$(NAME)

$(NAME): $(OBJ)
		echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME) \033[0mDONE!"
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
		echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m" 
	$(CC) $(FLAGS) -o $@ -c $<

clean:
		echo "\t\xF0\x9F\x92\xA3   Cleaning"
	rm -rf $(OBJ)

fclean: clean
		echo "\t\xF0\x9F\x9A\xBD   Full Clean"
	rm-rf $(NAME)

re: fclean all
