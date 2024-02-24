/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:25:29 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/24 11:47:33 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_to_a(t_list **stack_a, t_list **stack_b, int *table,
		int max)
{
	int	k;

	k = 0;
	while (*stack_b)
	{
		if (ft_check_max(*stack_b, table[max]))
		{
			if ((*stack_b)->value == table[max]
				|| ft_lstlast(*stack_b)->value == table[max])
			{
				first_last(stack_a, stack_b, table[max]);
				max--;
			}
			else if (k == 0 || ft_lstlast(*stack_a)->value < (*stack_b)->value)
				on_stack_a(stack_a, stack_b, &k);
			else
				moves(stack_b, table[max]);
		}
		else if (ft_check_max(*stack_a, table[max])
			&& ft_lstlast(*stack_a)->value == table[max])
			rest(stack_a, &max, &k);
	}
	while (max >= 0 && k != 0)
		rest(stack_a, &max, &k);
}
