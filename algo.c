/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:08:02 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/22 15:17:10 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_sort(t_list **stack_a, t_list **stack_b,int *table,
		int size_stack)
{
	

	push_a_to_b(stack_a, stack_b, table, size_stack);
	
	push_b_to_a(stack_a, stack_b, table, size_stack);
	
	
	
}
