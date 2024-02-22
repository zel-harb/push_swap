#include "push_swap.h"

void	reverseRotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	if (!(*stack) || ft_lstsize(*stack) == 1)
		return ;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;

}
void	rra(t_list **stack_a)
{
	reverseRotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}
void	rrb(t_list **stack_b)
{
	reverseRotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}
void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverseRotate(stack_a);
	reverseRotate(stack_b);
}