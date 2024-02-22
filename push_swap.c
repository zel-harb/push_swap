#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ( str[i] == 32)
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
		if(result > INT_MAX || result < INT_MIN)
		{
			// system("leaks push_swap");
			return((write(1,"Error\n",6)),exit(0),0);
		}
		i++;
	}
	return (result * sign);
}

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
	int		size_stack;
	int *table;

	(void)argc;
	if (argc == 1)
		return (0);
	if (ft_full(&stack_a, argv) == 1)
	{
		 freeList(stack_a);
		//  system("leaks push_swap");
		return (0);
	}
	size_stack = ft_lstsize(stack_a);
	
	if (size_stack == 1 || size_stack == 0)
	{
		if(size_stack == 1 )
		 freeList(stack_a);
		//  system("leaks push_swap");
		return (0);
	}
	table = (int *)malloc(size_stack * sizeof(int));
	full_array(table, size_stack, stack_a);
	ft_sort_int_tab(table, size_stack);

	 if (size_stack == 4 && !is_sorted(stack_a))
		algo_sort(&stack_a, &stack_b,table, size_stack);
	else if (size_stack <= 5 && !is_sorted(stack_a))
		mini_sort(&stack_a, &stack_b);
	else if (size_stack > 5 && !is_sorted(stack_a))
		algo_sort(&stack_a,&stack_b,table, size_stack);
	
	free(table);
	freeList(stack_a);
//  system("leaks push_swap");	
 
	return (0);
}
