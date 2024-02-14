#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*current;
	t_list	*tmpNode;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	current = *stack;
	tmpNode = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *stack;
	*stack = tmpNode->next;
	tmpNode->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}
void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}