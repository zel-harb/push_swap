#include "push_swap.h"

int	check_double(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = stack;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
			{
				ft_putstr_fd("Error\n", 1);
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	check_intervalle(char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_non_number(char **argv, int argc)
{
	int	j;
	int	i;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
			{
				ft_putstr_fd("Error\n", 1);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_num_is_valid(char **argv, int i)
{
	int	j;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(char **argv, int argc)
{
	if (check_non_number(argv, argc))
		return (1);
	if (check_intervalle(argv, argc))
		return (1);
	return (0);
}
