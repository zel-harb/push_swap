#include "push_swap.h"

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
	int		i;
    t_list	*new;
	i = 0;
	while (argv[i])
	{
		
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new);
		i++;
		//  freeList(new);
		
	}

	
}
// int	valide_args(char **argv, int argc)
// {
// 	int	i;
// 	int	size;
// 	int	k;
// 	int	j;

// 	j = 0;
// 	i = 1;
// 	k = 0;
// 	size = ft_strlen(argv[i]);
// 	if (size == 0)
// 		return (0);
// 	while (size != 0 && i < argc)
// 	{
// 		i++;
// 		size = ft_strlen(argv[i]);
// 		if (size == 0)
// 			return (0);
// 		i++;
// 	}
// 	i = 0;
// 	while (argv[i] && i < argc)
// 	{
// 		size = ft_strlen(argv[i]);
// 		while (argv[i][j])
// 		{
// 			if (argv[i][j] == ' ')
// 				k++;
// 			j++;
// 		}
// 		if (k == size)
// 			return (0);
// 		k = 0;
// 		j = 0;
// 		i++;
// 	}
// 	return (1);
// }
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
			ft_free(str,count);
			return (1);
		}
		full_split(stack, str);
		ft_free(str,count);
		i++;
	}
	if (check_double(*stack))
	{
		// ft_lstclear(stack,del);
		return (1);
	}
	return (0);
}
