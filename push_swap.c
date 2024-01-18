#include "push_swap.h"
int	ft_atoi( char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
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
void full(t_list **stack_a,char **argv)
{
    t_list *new;
    int i;
    i=1;
    while(argv[i])
    {
        new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}

    // stack_a->value= atoi(argv[i]);
    // stack_a->next;
    // i++;
    

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
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

    stack_a = (t_list *)malloc(sizeof(t_list));
	stack_b = (t_list *)malloc(sizeof(t_list));
	stack_a = NULL;
	stack_b = NULL;
    full(&stack_a,argv);
	full(&stack_b,argv);
	t_list *current =stack_a;
	t_list *current1 =stack_b;
	t_list *z=stack_b;
	//rr(stack_a,stack_b);
	//rra(z);
    while(current || z )
    {
		printf("%d  |  %d\n",current->value,z->value);
        current = current->next;
		z = z->next;
    }
	//  sa(stack_a);
	// printf("--------------------- \n");
	//   while(stack_a)
    // {
		
    //     printf("%d \n",stack_a->value);
    //      stack_a = stack_a->next;
    // }
}
