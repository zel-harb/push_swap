/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:52:09 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/26 18:03:47 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
