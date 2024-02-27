/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:23:34 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/27 15:18:55 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	full_array(int *table, int size, t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a && i < size)
	{
		table[i] = stack_a->value;
		stack_a = stack_a->next;
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || !s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	full_moves(t_list **stack_a)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *stack_a;
	while (current)
	{
		current->moves = i;
		current = current->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	if (ft_full	(&stack_a, argv,argc) == 1)
	{
		free_list(stack_a);
		return (0);
	}
	if (ft_lstsize(stack_a) == 1 || ft_lstsize(stack_a) == 0)
	{
		if (ft_lstsize(stack_a) == 1)
			free_list(stack_a);
		return (0);
	}
	if (ft_lstsize(stack_a) == 4 && !is_sorted(stack_a))
		algo_sort(&stack_a, &stack_b, ft_lstsize(stack_a));
	else if (ft_lstsize(stack_a) <= 5 && !is_sorted(stack_a))
		mini_sort(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) > 5 && !is_sorted(stack_a))
		algo_sort(&stack_a, &stack_b, ft_lstsize(stack_a));
	free_list(stack_a);
	return (0);
}
