#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//# include "../libft/libft.h"
typedef struct s_list
{
	int				value;
	int				moves;
	struct s_list	*next;
}					t_list;

// list
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);

// put
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);

// Swap
void				swap(t_list *stack_a);
void				sb(t_list **stack_b);
void				sa(t_list **stack_a);
void				ss(t_list **stack_a, t_list **stack_b);

// Rotatae
void				rotate(t_list **stack);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);

// Reverse
void				reverseRotate(t_list **stack);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);

// Push
void				push(t_list **stack_1, t_list **stack_2);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);

// Sort
int					is_sorted(t_list *stack);
void				algo_sort(t_list **stack_a, t_list **stack_b, int *table,
						int size);
void				ft_sort_int_tab(int *tab, int size);

// utilise
int					is_sorted(t_list *stack);
int					get_max(t_list *stack);
void				mini_sort(t_list **stack, t_list **stack_b);
void				algo_sort(t_list **stack_a, t_list **stack_b, int *table,
						int size_stack);
void				full_moves(t_list **stack_a);
int					get_min(t_list *stack);
int					is_be(t_list *stack_a, int integer);
long				ft_atoi(char *str);
// display
void				displayList(t_list **current);

// push
void				push_a_to_b(t_list **stack_a, t_list **stack_b, int *table,
						int size_stack);
void				push_b_to_a(t_list **stack_a, t_list **stack_b, int *table,
						int size_stack);
// Error
int					check_error(char **argv, int argc);
// int check_double(char **argv,int argc);
char				**ft_split(char const *s, char c);
int					ft_full(t_list **stack, char **argv,int argc);
void				full(t_list **stack_a, char **argv);
void				full_split(t_list **stack_a, char **argv);
int					count_words(char const *s, char c);
int					check_double(t_list *stack);
size_t	ft_strlen(char *str);

#endif