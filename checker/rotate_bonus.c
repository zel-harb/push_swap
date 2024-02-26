/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:54:01 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/26 17:54:15 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_list **stack)
{
	t_list	*current;
	t_list	*tmpnode;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	current = *stack;
	tmpnode = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *stack;
	*stack = tmpnode->next;
	tmpnode->next = NULL;
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
