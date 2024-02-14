#include "push_swap.h"

void	algo_sort(t_list **stack_a, t_list **stack_b, int *table,
		int size_stack)
{
	push_a_to_b(stack_a, stack_b, table, size_stack);
	push_b_to_a(stack_a, stack_b, table, size_stack);
}