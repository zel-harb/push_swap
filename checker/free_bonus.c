/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:42:07 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/26 17:50:26 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	valide_args(int size, int argc, char **argv)
{
	int	i;

	i = 1;
	while (size != 0 && i < argc)
	{
		size = ft_strlen_bonus(argv[i]);
		if (size == 0)
			return (0);
		i++;
	}
	return (1);
}

int	valide_args_vide(char **argv, int argc)
{
	int	i;
	int	j;
	int	k;
	int	size;

	j = 0;
	k = 0;
	i = 1;
	while (argv[i] && i < argc)
	{
		size = ft_strlen_bonus(argv[i]);
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				k++;
			j++;
		}
		if (k == size)
			return (0);
		k = 0;
		j = 0;
		i++;
	}
	return (1);
}

int	valide_args_bonus(char **argv, int argc)
{
	int	i;
	int	size;
	int	k;
	int	j;

	j = 0;
	i = 1;
	k = 0;
	size = ft_strlen_bonus(argv[i]);
	if (size == 0)
		return (0);
	if (valide_args(size, argc, argv) == 0)
		return (0);
	if (valide_args_vide(argv, argc) == 0)
		return (0);
	return (1);
}

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
