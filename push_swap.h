#include <stdlib.h>
#include <stdio.h> 
# include <string.h>
# include <unistd.h>
//# include "../libft/libft.h"
typedef struct s_list
{
	int				value;
	int 			moves;
	struct s_list	*next;
}   t_list;
int	ft_atoi(char *str);
//list
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
//Swap
void swap(t_list *stack_a);
void sb(t_list **stack_b);
void sa(t_list **stack_a);
void ss(t_list **stack_a,t_list **stack_b);
 //Rotatae
 void rotate(t_list **stack);
void  ra(t_list **stack_a);
 void  rb(t_list **stack_b);
 void rr(t_list **stack_a,t_list **stack_b);
 //R
void	reverseRotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
//Push
void push(t_list **stack_1,t_list **stack_2);
void	pa(t_list **stack_a,t_list **stack_b);
void	pb(t_list **stack_b,t_list **stack_a);
//Sort
int is_sorted(t_list *stack);
void chismia(t_list **stack,t_list **stack_b);
int get_max(t_list *stack);
void algo_sort(t_list **stack_a,t_list **stack_b, int *table,int size);
//Sort table
void	ft_sort_int_tab(int *tab, int size);

//algo 
//void algo(t_list **stack_a,t_list **stack_b,int *table,int size);
//void algo_1(t_list **stack_a,t_list **stack_b, int *table,int size_stack);
void algoo_3(t_list **stack_a,t_list **stack_b, int *table,int size_stack);
void full_moves(t_list **stack_a);

void push_to_a(t_list **stack_a,t_list **stack_b,int *table,int size);
int ft_check_max(t_list *stack,int max);