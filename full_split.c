/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:26:24 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/24 15:19:38 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_be(t_list *stack_a, int integer)
{
	while (stack_a)
	{
		if (integer == stack_a->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

long double		ft_atoi(char *str)
{
	int		i;
	long double	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}

void	full_split(t_list **stack_a, char **argv)
{
	int		i;
	t_list	*new;

	i = 0;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
}

int	ft_full(t_list **stack, char **argv)
{
	char	**str;
	int		count;
	int		i;

	i = 1;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		count = count_words(argv[i], ' ');
		if (check_error(str, count))
		{
			ft_free(str, count);
			return (1);
		}
		full_split(stack, str);
		ft_free(str, count);
		i++;
	}
	if (check_double(*stack))
		return (1);
	return (0);
}
