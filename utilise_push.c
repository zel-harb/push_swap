#include "push_swap.h"
void	first_last(t_list **stack_a, t_list **stack_b, int max)
{
	if ((*stack_b)->value == max)
		pa(stack_b, stack_a);
	else if (ft_lstlast(*stack_b)->value == max)
	{
		rrb(stack_b);
		pa(stack_b, stack_a);
	}
}

void	moves(t_list **stack_b, int max)
{
	full_moves(stack_b);
	if (find_max(*stack_b, max) < (ft_lstsize(*stack_b) / 2))
	{
		if (find_max(*stack_b, max) != 0)
			rb(stack_b);
	}
	else
	{
		if (find_max(*stack_b, max) != 0)
			rrb(stack_b);
	}
}
void	rest(t_list **stack_a, int *max, int *k)
{
	rra(stack_a);
	(*max)--;
	(*k)--;
}
void	on_stack_a(t_list **stack_a, t_list **stack_b, int *k)
{
	pa(stack_b, stack_a);
	ra(stack_a);
	(*k)++;
}

int	find_near(t_list *stack_a, int *table, int the_end, int start)
{
	int	save;

	save = start;
	while (stack_a)
	{
		while (save <= the_end)
		{
			if (stack_a->value == table[save])
				return (stack_a->moves);
			save++;
		}
		stack_a = stack_a->next;
		save = start;
	}
	return (-1);
}