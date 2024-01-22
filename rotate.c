#include "push_swap.h"


void rotate(t_list **stack)
{
    if (*stack == NULL || (*stack)->next == NULL) {
        // No rotation needed for empty or single-node list
        return;
    }

    t_list *current = *stack;
    t_list *tmpNode = *stack;

    // Traverse the list to find the last node
    while (current->next != NULL)
    {
        current = current->next;
    }

    // Assign the address of the first node to the last node
    current->next = *stack;

    // Update the head of the list to the second node
    *stack = tmpNode->next;

    // Set the next of the original first node to NULL
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