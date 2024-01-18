#include <stdlib.h>
#include <stdio.h>
# include <string.h>
# include <unistd.h>
//# include "../libft/libft.h"
typedef struct s_list
{
	int				value;
	struct s_list	*next;
}   t_list;
int	ft_atoi(char *str);
//list
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
//Swap
int swap(t_list *stack_a);
int sb(t_list *stack_b);
 int ss(t_list *stack_a,t_list *stack_b);
int sa(t_list *stack_a);
 //Rotatae
 int rotate(t_list *stack);
int  ra(t_list *stack_a);
 int  rb(t_list *stack_b);
 int rr(t_list *stack_a,t_list *stack_b);
 //R
int	reverseRotate(t_list **stack);
 int	rra(t_list *stack_a);