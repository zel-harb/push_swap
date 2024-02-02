#include "push_swap.h"


void rotate(t_list **stack)
{
    if (*stack == NULL || (*stack)->next == NULL) {
        return;
    }

    t_list *current = *stack;
    t_list *tmpNode = *stack;

    while (current->next != NULL)
    {
        current = current->next;
    }

    
    current->next = *stack;
    *stack = tmpNode->next;
    tmpNode->next = NULL;
}
    


void  ra(t_list **stack_a)
{
    rotate(stack_a);
    ft_putstr_fd("ra\n",1);

}
void  rb(t_list **stack_b)
{
    rotate(stack_b);
    ft_putstr_fd("rb\n",1);

}