CC = cc
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
SOURCES = push_swap.c operations.c reverseRotate.c rotate.c sort.c swap.c liste.c alog.c
OBJECTS = $(SOURCES:.c=.o)
all: $(NAME)

$(NAME): $(OBJECTS)
.c.o:
	$(CC) $(FLAGS) -c $<
	ar rcs $(NAME) $@

# $(OBJECTS):
# 	mkdir $(OBJECTS)
clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

# test2:				$(NAME)	
# 					$(eval ARG = $(shell shuf -i 0-100 -n 2))
# 					./push_swap $(ARG) | ./checker_linux $(ARG)
# 					@echo -n "Instructions: "
# 					@./push_swap $(ARG) | wc -l