CC = cc 
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
#-fsanitize=address -g3
CHECKER= checker
SOURCES = push_swap.c \
	operations.c \
	reverseRotate.c \
	rotate.c \
	sort.c \
	swap.c \
	liste.c \
	algo.c \
	push_a_to_b.c \
	push_b_to_a.c \
	utilise.c \
	error.c \
	split.c \
	free.c \
	utilise_push.c \
	full_split.c

OBJECTS = $(SOURCES:.c=.o)

SOURCES_BONUS = checker/checker_mac.c \
			checker/get_next_line.c \
			checker/get_next_line_utils.c \
			checker/list_bonus.c \
			checker/use_bonus.c \
			checker/operation_bonus.c \


BOBJECTS = $(SOURCES_BONUS:.c=.o)
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)
bonus: $(CHECKER)
$(CHECKER):$(BOBJECTS)
		$(CC) $(FLAGS) $(BOBJECTS) -o $(CHECKER)




clean:
	rm -rf $(OBJECTS) $(BOBJECTS)
	
fclean: clean
	rm -f $(NAME) $(BOBJECTS)

re: fclean all

