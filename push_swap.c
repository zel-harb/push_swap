#include "push_swap.h"
long	ft_atoi( char *str)
{
	int	i;
	long	result;
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
void full_array(int *table,int size,t_list *stack_a)
{
	int i;
	i =0;
	while (stack_a && i <size)
	{
		table[i]=stack_a->value;
		stack_a=stack_a->next;
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
void displayList(t_list **current) {
    t_list *temp = *current;  

    while (temp != NULL) {
        printf("%d \n", temp->value);
        temp = temp->next;
    }
}
void full_moves(t_list **stack_a)
{
    int i = 0;
    t_list *current ;
	current= *stack_a; 

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
	int size_stack;
	int *table;

	
    if(argc ==2)
	{
		if(ft_full(&stack_a,argv))
			return 0;
		
	}
	else
	{
		if(check_error(argv,argc))
		return 0;
    	full(&stack_a,argv);
		full_moves(&stack_a);
	}
    size_stack =ft_lstsize(stack_a);
	table=(int *)malloc(size_stack * sizeof(int));
	
	full_array(table,size_stack,stack_a);
	ft_sort_int_tab(table,size_stack);
	if(size_stack==1 || size_stack==0)
		return 0;	
	else if(size_stack==4 && !is_sorted(stack_a))
	 algo_sort(&stack_a,&stack_b,table,size_stack);
	else if(size_stack <=5 && !is_sorted(stack_a))
		mini_sort(&stack_a,&stack_b);
	else if (size_stack > 5 && !is_sorted(stack_a))
		algo_sort(&stack_a,&stack_b,table,size_stack);
    //  printf("----------------------->b\n");
	//  displayList(&stack_b);
	//  printf("----------------------->a\n");
	//  displayList(&stack_a);
//   if(is_sorted(stack_a)==1)
// 	     printf("\nssssssssl\n");
//     else 
//     printf("nnnnnnnnnnnnnnnnnnn\n");
		return 0;
    
}
