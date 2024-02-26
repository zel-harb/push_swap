/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:34:52 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/26 18:55:19 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	valid_moves(char *str)
{
	char	*name_moves[12];
	int		i;

	i = 0;
	name_moves[0] = "sa\n";
	name_moves[1] = "sb\n";
	name_moves[2] = "ss\n";
	name_moves[3] = "pa\n";
	name_moves[4] = "pb\n";
	name_moves[5] = "ra\n";
	name_moves[6] = "rb\n";
	name_moves[7] = "rr\n";
	name_moves[8] = "rra\n";
	name_moves[9] = "rrb\n";
	name_moves[10] = "rrr\n";
	name_moves[11] = NULL;
	while (name_moves[i])
	{
		if (ft_strcmp(str, name_moves[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_moves(char *line)
{
	if (valid_moves(line) != 0)
		return (1);
	return (0);
}

void	ft_action(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa_bonus(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_bonus(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa_bonus(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra_bonus(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_bonus(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb_bonus(stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra_bonus(stack_a);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_bonus(stack_a, stack_b);
}

int	ft_push(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (check_valid_moves(line) != 0)
		{
			free(line);
			return (1);
		}
		ft_action(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
