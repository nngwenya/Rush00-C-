NAME = ft_retro
FLAG = -Wall -Wextra -Werror
SOURCE = Player.cpp Enemy.cpp Bullet.cpp Vector.cpp main.cpp

all: $(NAME)

$(NAME):
	@clang++ -lncurses $(FLAGS) -o $(NAME) $(SOURCE)
	@echo "Compiled";

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
