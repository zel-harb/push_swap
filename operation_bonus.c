#include "push_swap_bonus.h"

static void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (*stack_1 == NULL)
		return ;
	tmp = *stack_1;
	*stack_1 = tmp->next;
	tmp->next = *stack_2;
	*stack_2 = tmp;
}
void	pa_bonus(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}
void	pb_bonus(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
}
static void	reverseRotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	

	head = *stack;
    if(!head || head->next==NULL)
        return;
	tail = ft_lstlast_bonus(head);

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
void	rra_bonus(t_list **stack_a)
{
	reverseRotate(stack_a);
	
}
void	rrb_bonus(t_list **stack_b)
{
	reverseRotate(stack_b);
}
void rrr_bonus(t_list **stack_a,t_list **stack_b)
{

	reverseRotate(stack_b);
	reverseRotate(stack_a);

}
static void	rotate(t_list **stack)
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

void	ra_bonus(t_list **stack_a)
{
	rotate(stack_a);
}
void	rb_bonus(t_list **stack_b)
{
	rotate(stack_b);
}
void	rr_bonus(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

static void	swap(t_list *stack_a)
{
	t_list	*tmp;
	int		val;
	int		val2;

	if (ft_lstsize_bonus(stack_a) < 2)
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
void	sa_bonus(t_list **stack_a)
{
	swap(*stack_a);
}
void	sb_bonus(t_list **stack_b)
{
	swap(*stack_b);
}
void	ss_bonus(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
}