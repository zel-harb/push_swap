CC = cc
NAME = push_swap
#FLAGS = -Wall -Wextra -Werror
SOURCES = push_swap.c operations.c reverseRotate.c rotate.c sort.c swap.c liste.c alog.c algo2.c algofinal.c
OBJECTS = $(SOURCES:.c=.o)
all: $(NAME)

$(NAME): $(OBJECTS)
.c.o:
	$(CC) $(FLAGS) -c $<
	ar rcs $(NAME) $@


clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

