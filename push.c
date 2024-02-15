#include "push_swap.h"

int	ft_check_max(t_list *stack, int max)
{
	while (stack)
	{
		if (max == stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
int	find_max(t_list *stack, int max)
{
	while (stack)
	{
		if (stack->value == max)
			return (stack->moves);
		stack = stack->next;
	}
	return (-1);
}

void	push_a_to_b(t_list **stack_a, t_list **stack_b, int *table,
		int size_stack)
{
	int	mid;
	int	offset;
	int	start;
	int	the_end;

	offset = 0;
	mid = (size_stack / 2) - 1;
	if (size_stack > 3)
		offset = 1;
	if (size_stack > 5)
		offset = 2;
	if (size_stack > 50)
		offset = 8;
	if (size_stack > 150)
		offset = 30;
	start = mid - offset;
	the_end = mid + offset;
	while ((*stack_a))
	{
		if (ft_lstsize(*stack_a) == 1)
			pb(stack_a, stack_b);
		while (ft_lstsize(*stack_b) < the_end - start+1)
		{
			if ((*stack_a)->value >= table[start]
				&& (*stack_a)->value <= table[the_end])
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->value < table[mid])
					rb(stack_b);
			}
			else
				ra(stack_a);
		}
		start = start - offset;
		if (start < 0)
			start = 0;
		the_end = the_end + offset;
		if (the_end >= size_stack)
			the_end = size_stack - 1;
	}
}

void	push_b_to_a(t_list **stack_a, t_list **stack_b, int *table,
		int size_stack)
{
	int	max;

	max = size_stack - 1;
	while (*stack_b)
	{
		while (ft_check_max(*stack_b, table[max]))
		{
			if ((*stack_b)->value == table[max])
				pa(stack_b, stack_a);
			else if ((*stack_b)->value == table[max - 1]
				&& (*stack_b)->next->value == table[max])
			{
				pa(stack_b, stack_a);
				pa(stack_b, stack_a);
				sa(stack_a);
				max--;
			}
			else if (ft_lstlast(*stack_b)->value == table[max])
			{
				rrb(stack_b);
				pa(stack_b, stack_a);
			}
			else
			{
				full_moves(stack_b);
				if (find_max(*stack_b, table[max]) < (ft_lstsize(*stack_b) / 2))
				{
					if (find_max(*stack_b, table[max]) != 0)
						rb(stack_b);
				}
				else
				{
					if (find_max(*stack_b, table[max]) != 0)
						rrb(stack_b);
				}
			}
			if (!ft_check_max(*stack_b, table[max]))
				max--;	
		}
	}
}
