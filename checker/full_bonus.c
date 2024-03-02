/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:02:37 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/27 16:39:29 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	full_split(t_list **stack_a, char **argv)
{
	t_list	*new;
	int		i;

	i = 0;
	while (argv[i])
	{
		new = ft_lstnew_bonus(ft_atoi_bonus(argv[i]));
		ft_lstadd_back_bonus(stack_a, new);
		i++;
	}
}

int	ft_full_bonus(t_list **stack, char **argv, int argc)
{
	char	**str;
	int		count;
	int		i;

	i = 0;
	if (valide_args_bonus(argv, argc) == 0)
	{
		ft_putstr_fd_bonus("Error\n", 2);
		return (1);
	}
	while (argv[++i])
	{
		str = ft_split(argv[i], ' ');
		count = count_words(argv[i], ' ');
		if (check_error_bonus(str, count))
		{
			ft_free(str, count);
			return (1);
		}
		full_split(stack, str);
		ft_free(str, count);
	}
	if (check_double_bonus(*stack))
		return (1);
	return (0);
}
