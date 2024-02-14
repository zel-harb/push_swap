#include "push_swap.h"
#include <stdio.h>

void	swap(t_list *stack_a)
{
	t_list	*tmp;
	int		val;
	int		val2;

	if (ft_lstsize(stack_a) < 2)
		return ;
	tmp = stack_a;
	val = tmp->value;
	tmp = tmp->next;
	val2 = tmp->value;
	tmp = stack_a;
	tmp->value = val2;
	tmp = tmp->next;
	tmp->value = val;
}
void	sa(t_list **stack_a)
{
	swap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}
void	sb(t_list **stack_b)
{
	swap(*stack_b);
	ft_putstr_fd("sb\n", 1);
}
void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr_fd("ss\n", 1);
}