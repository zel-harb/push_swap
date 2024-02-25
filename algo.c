/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:08:02 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/25 01:42:31 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	algo_sort(t_list **stack_a, t_list **stack_b, int size_stack)
{
	int	max;
	int	*table;

	table = (int *)malloc(ft_lstsize(*stack_a) * sizeof(int));
	full_array(table, ft_lstsize(*stack_a), *stack_a);
	ft_sort_int_tab(table, ft_lstsize(*stack_a));
	max = size_stack - 1;
	push_a_to_b(stack_a, stack_b, table, size_stack);
	push_b_to_a(stack_a, stack_b, table, max);
	free(table);
}
