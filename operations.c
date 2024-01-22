#include "push_swap.h"

void push(t_list **stack_1,t_list **stack_2)
{
     if (*stack_1 == NULL) {
        // Handle case where stack_1 is empty
        return;
    }

    t_list *tmp = *stack_1;

    // Remove the first node from stack_1
    *stack_1 = tmp->next;

    // Add the removed node to the front of stack_2
   tmp->next = *stack_2;
    *stack_2 = tmp;
}
void	pa(t_list **stack_a,t_list **stack_b)
{
	 push(stack_a,stack_b);
	 ft_putstr_fd("pa\n", 1);
	
}
void	pb(t_list **stack_b,t_list **stack_a)
{
	 push(stack_b,stack_a);
	 ft_putstr_fd("pb\n", 1);
	
}




