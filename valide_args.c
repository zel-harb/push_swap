/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:52:51 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/27 15:27:44 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valide_args1(int size, int argc, char **argv)
{
	int	i;

	i = 1;
	while (size != 0 && i < argc)
	{
		size = ft_strlen(argv[i]);
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
		size = ft_strlen(argv[i]);
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

int	valide_args(char **argv, int argc)
{
	int	i;
	int	size;
	int	k;
	int	j;

	j = 0;
	i = 1;
	k = 0;
	size = ft_strlen(argv[i]);
	if (size == 0)
		return (0);
	if (valide_args1(size, argc, argv) == 0)
		return (0);
	if (valide_args_vide(argv, argc) == 0)
		return (0);
	return (1);
}
