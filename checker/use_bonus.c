/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:43:55 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/26 09:53:49 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long double	ft_atoi_bonus(char *str)
{
	int			i;
	long double	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32)
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

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd_bonus(char *s, int fd)
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

int	check_double_bonus(t_list *stack)
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
				ft_putstr_fd_bonus("Error\n", 1);
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
		if (ft_atoi_bonus(argv[i]) > INT_MAX
			|| ft_atoi_bonus(argv[i]) < INT_MIN)
		{
			ft_putstr_fd_bonus("Error\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	mcheck_non_number(char **argv, int i, int j)
{
	if (argv[i][j] < '0' || argv[i][j] > '9')
	{
		if (argv[i][j] != '-' && argv[i][j] != '+')
			return (1);
	}
	if (argv[i][j] == '+' || argv[i][j] == '-')
	{
		if (argv[i][j + 1] < '0' || argv[i][j + 1] > '9')
			return (1);
		if ((j - 1) >= 0)
		{
			if (argv[i][j - 1] >= '0' || argv[i][j - 1] <= '9')
				if (argv[i][j + 1] >= '0' || argv[i][j + 1] <= '9')
					return (1);
		}
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
			if (mcheck_non_number(argv, i, j) == 1)
			{
				ft_putstr_fd_bonus("Error\n", 1);
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

int	check_error_bonus(char **argv, int argc)
{
	if (check_non_number(argv, argc))
		return (1);
	if (check_intervalle(argv, argc))
		return (1);
	return (0);
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
	while (size != 0 && i < argc)
	{
		size = ft_strlen_bonus(argv[i]);
		if (size == 0)
			return (0);
		i++;
	}
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
char	**ft_free(char **s, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	cmp;
	int	vrf;

	i = 0;
	cmp = 0;
	vrf = 0;
	while (s[i])
	{
		if (s[i] != c && vrf == 0)
		{
			cmp++;
			vrf = 1;
		}
		else if (s[i] == c)
			vrf = 0;
		i++;
	}
	return (cmp);
}

static char	*ft_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(end - start + 1);
	if (!word)
		return (0);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static char	**set_word(const char *str, char c, int l)
{
	int		i;
	char	**p;
	int		start;
	int		j;

	i = 0;
	j = 0;
	start = 0;
	p = (char **)malloc(sizeof(char *) * (l + 1));
	if (!p)
		return (NULL);
	while (str[i] && j < l)
	{
		while (str[i++] == c)
			start = i;
		while (str[i] != c && str[i])
			i++;
		p[j] = ft_word(str, start, i);
		if (!p[j])
			return (ft_free(p, j));
		j++;
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		len;

	if (s == NULL)
		return (NULL);
	len = count_words(s, c);
	word = set_word(s, c, len);
	return (word);
}

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

	i = 1;
	if (valide_args_bonus(argv, argc) == 0)
	{
		ft_putstr_fd_bonus("Error\n", 1);
		return (1);
	}
	while (argv[i])
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
		i++;
	}
	if (check_double_bonus(*stack))
		return (1);
	return (0);
}

