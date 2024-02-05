CC = cc 
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
#-fsanitize=address -g3
SOURCES = push_swap.c operations.c reverseRotate.c rotate.c sort.c swap.c liste.c   algo.c push.c utilise.c
OBJECTS = $(SOURCES:.c=.o)
all: $(NAME)

$(NAME): $(OBJECTS)
.c.o:
	$(CC) $(FLAGS) -c $<
	


clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

