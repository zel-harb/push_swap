/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_mac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:08:51 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/24 00:29:39 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted_bonus(t_list *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

size_t	ft_strlen_bonus(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *name_moves)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (name_moves[i])
	{
		if (name_moves[i] == s1[i])
			k++;
		i++;
	}
	if (k == 3)
		return (0);
	else if (k == 4)
		return (0);
	return (1);
}

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

int	ft_push(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (check_valid_moves(line) != 0)
			return (1);
		else if (ft_strcmp(line, "sa\n") == 0)
			sa_bonus(stack_a);
		if (ft_strcmp(line, "sb\n") == 0)
		{
			printf("hi\n");
			sb_bonus(stack_b);
		}
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
		if (ft_strcmp(line, "rra\n") == 0)
			rra_bonus(stack_a);
		else if (ft_strcmp(line, "rrr\n") == 0)
			rrr_bonus(stack_a, stack_b);
		line = get_next_line(0);
	}
	return (0);
}

void	displaylist_list(t_list **current)
{
	t_list	*temp;

	temp = *current;
	while (temp != NULL)
	{
		printf("%d \n", temp->value);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	(void)argc;
	if (argc == 1)
		return (0);
	if (ft_full_bonus(&stack_a, argv, argc) == 1)
		return (0);
	if (is_sorted_bonus(stack_a) == 1)
	{
		ft_putstr_fd_bonus("OK\n", 1);
		return (0);
	}
	if (ft_push(&stack_a, &stack_b) == 1)
	{
		ft_putstr_fd_bonus("Error\n", 1);
		return (0);
	}
	if (is_sorted_bonus(stack_a) == 1 && !stack_b)
		ft_putstr_fd_bonus("OK\n", 1);
	else
		ft_putstr_fd_bonus("KO\n", 1);
	// printf("stack __________________a\n");
	// displayList_list(&stack_a);
	// printf("stack __________________b\n");
	// displayList_list(&stack_b);
	return (0);
}
