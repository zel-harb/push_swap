#include "push_swap_bonus.h"

int	is_sorted_bonus(t_list *stack)
{
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
	int	k;

	i = 0;
	k = 0;
	while (name_moves[i])
	{
		if (name_moves[i] == s1[i])
			k++;
		i++;
	}
	if (k == 3)
		return (0);
	else if (k == 4)
		return (0);
	return (1);
}
int	check_valid_moves(void)
{
	char	*line;
	int		i;
	char	*name_moves[12];

	name_moves[0] = "sa\n";
	name_moves[1] = "sb\n";
	name_moves[2] = "ss\n";
	name_moves[3] = "pa\n";
	name_moves[4] = "pb\n";
	name_moves[5] = "ra\n";
	name_moves[6] = "rb\n";
	name_moves[7] = "rr\n";
	name_moves[8] = "rra\n";
	name_moves[9] = "rrb\n";
	name_moves[10] = "rrr\n";
	name_moves[11] = NULL;
	line = get_next_line(0);
	i = 0;
	while (line)
	{
		while (name_moves[i])
		{
			if (ft_strcmp(line, name_moves[i]) == 1)
			{
				return (1);
				break ;
			}
			i++;
		}
		line = get_next_line(0);
		i = 0;
	}
	return (0);
}
void	ft_push(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "sa\n") == 0)
			sa_bonus(stack_a);
		else if (ft_strcmp(line, "sb\n") == 0)
			sb_bonus(stack_b);
		else if (ft_strcmp(line, "ss\n") == 0)
			ss_bonus(stack_a, stack_b);
		else if (ft_strcmp(line, "pa\n") == 0)
			pa_bonus(stack_b, stack_a);
		else if (ft_strcmp(line, "pb\n") == 0)
			pb_bonus(stack_a, stack_b);
		else if (ft_strcmp(line, "ra\n") == 0)
			ra_bonus(stack_a);
		else if (ft_strcmp(line, "rb\n") == 0)
			rb_bonus(stack_b);
		else if (ft_strcmp(line, "rr\n") == 0)
			rr_bonus(stack_a, stack_b);
		else if (ft_strcmp(line, "rrb\n") == 0)
			rrb_bonus(stack_b);
		else if (ft_strcmp(line, "rra\n") == 0)
			rra_bonus(stack_a);
		//  else if(ft_strcmp(line,name_moves[10])==0)
		//     rrr_bonus(stack_b);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	(void)argc;

	if (ft_full_bonus(&stack_a, argv,argc) == 1)
		return (0);
	// if(check_valid_moves()==0)
	//     return (0);
	ft_push(&stack_a, &stack_b);
	if (is_sorted_bonus(stack_a) == 1 && !stack_b)
		ft_putstr_fd_bonus("OK\n", 1);
	else
		ft_putstr_fd_bonus("KO\n", 1);
	return (0);
}