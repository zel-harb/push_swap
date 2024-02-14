CC = cc 
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
#-fsanitize=address -g3
SOURCES = push_swap.c \
	operations.c \
	reverseRotate.c \
	rotate.c \
	sort.c \
	swap.c \
	liste.c \
	algo.c \
	push.c \
	utilise.c \
	error.c \
	split.c

OBJECTS = $(SOURCES:.c=.o)
SOURCES_BONUS = checker_mac.c \
			get_next_line.c \
			get_next_line_utils.c \
			list_bonus.c \
			use_bonus.c \
			operation_bonus.c \


BOBJECTS = $(SOURCES_BONUS:.c=.o)
all: $(NAME)

$(NAME): $(OBJECTS)
bonus: $(BOBJECTS)
.c.o:
	$(CC) $(FLAGS) -c $<
	


clean:
	rm -rf $(OBJECTS) $(BOBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

