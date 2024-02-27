/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:08:51 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/27 15:19:11 by zel-harb         ###   ########.fr       */
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

	i = 0;
	while (name_moves[i])
	{
		if (name_moves[i] != s1[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_sort(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted_bonus(stack_a) == 1 && !stack_b)
		ft_putstr_fd_bonus("OK\n", 1);
	else
		ft_putstr_fd_bonus("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	if (ft_full_bonus(&stack_a, argv, argc) == 1)
	{
		free_list(stack_a);
		return (0);
	}
	if (ft_push(&stack_a, &stack_b) == 1)
	{
		ft_putstr_fd_bonus("Error\n", 1);
		free_list(stack_a);
		return (0);
	}
	check_sort(stack_a, stack_b);
	free_list(stack_a);
	if (ft_lstsize_bonus(stack_b) != 0)
		free_list(stack_b);
	return (0);
}
