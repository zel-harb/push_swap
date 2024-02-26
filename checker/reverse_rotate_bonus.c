/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:55:31 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/26 18:00:08 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	if (!(*stack) || ft_lstsize_bonus(*stack) == 1)
		return ;
	tail = ft_lstlast_bonus(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
}

void	rra_bonus(t_list **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb_bonus(t_list **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr_bonus(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_b);
	reverse_rotate(stack_a);
}
