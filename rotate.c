/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:18:56 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/23 08:32:33 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*current;
	t_list	*tmpnode;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	tmpnode = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	*stack = tmpnode->next;
	tmpnode->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
