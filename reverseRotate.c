#include "push_swap.h"

void	reverseRotate(t_list **stack)
{
	t_list	*head=*stack;
	t_list	*tail;

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