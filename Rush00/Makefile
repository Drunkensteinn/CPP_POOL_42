NAME = ft_retro
WWW = -Wall -Wextra -Werror
FLAGS = -lncurses
SRC_PATH = .
SRC_FILES = Bullets.cpp EnemyObj.cpp Plane.cpp main.cpp BulletObj.cpp Enemy.cpp GameRush.cpp
SRC_FULL = $(patsubst %.cpp, $(SRC_PATH)/%.cpp, $(SRC_FILES))
OBJECTS = $(patsubst %.cpp, $(SRC_PATH)/%.o, $(SRC_FILES))
.PHONY: all clean fclean re
all: $(NAME)
$(NAME):
	clang++ -o $(NAME) $(SRC_FULL) $(WWW) $(FLAGS) $(LIBRARI)
%.o: $(SRC_PATH)/%.cpp
	gcc $(WWW) -c -o $@ $<
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re:	fclean all
