/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:52:37 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/24 11:55:09 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	choice_move(t_list **stack_a, int *table, int the_end, int start)
{
	int	i;
	int	j;

	i = find_near(*stack_a, table, the_end, start);
	while (i > 0)
	{
		ra(stack_a);
		i--;
	}
}

int	choice_offset(int size_stack)
{
	int	offset;

	if (size_stack > 3)
		offset = 1;
	if (size_stack > 5)
		offset = 2;
	if (size_stack > 50)
		offset = 8;
	if (size_stack > 150)
		offset = size_stack / 20;
	return (offset);
}

t_para	*ft_para_lstnew(int content, int content1)
{
	t_para	*new;

	new = (t_para *)malloc(sizeof(t_para));
	if (new == NULL)
		return (NULL);
	new->offset = content;
	new->mid = content1;
	new->start = new->mid - new->offset;
	new->the_end = new->mid + new->offset;
	new->next = NULL;
	return (new);
}

void	a_to_b(t_list **stack_a, t_list **stack_b, t_para *para, int *table)
{
	while (ft_lstsize(*stack_b) < para->the_end - para->start)
	{
		if ((*stack_a)->value >= table[para->start]
			&& (*stack_a)->value <= table[para->the_end])
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->value < table[para->mid])
				rb(stack_b);
		}
		else
		{
			full_moves(stack_a);
			choice_move(stack_a, table, para->the_end, para->start);
			pb(stack_a, stack_b);
			if ((*stack_b)->value < table[para->mid])
				rb(stack_b);
		}
	}
}

void	push_a_to_b(t_list **stack_a, t_list **stack_b, int *table,
		int size_stack)
{
	t_para	*para;

	para = ft_para_lstnew(choice_offset(size_stack), (size_stack / 2) - 1);
	while ((*stack_a))
	{
		if (ft_lstsize(*stack_a) == 1)
			pb(stack_a, stack_b);
		while (ft_lstsize(*stack_b) < para->the_end - para->start)
			a_to_b(stack_a, stack_b, para, table);
		para->start = para->start - para->offset;
		if (para->start < 0)
			para->start = 0;
		para->the_end = para->the_end + para->offset;
		if (para->the_end >= size_stack)
			para->the_end = size_stack - 1;
	}
}
