#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
int	get_max(t_list *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}
int	get_min(t_list *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}
int	is_be(t_list *stack_a, int integer)
{
	while (stack_a)
	{
		if (integer == stack_a->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
size_t	ft_strlen(char *str)
{
	size_t i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}