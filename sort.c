#include "push_swap.h"

int is_sorted(t_list *stack)
{
    while(stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack=stack->next;
        
    }
    return 1;
}
int get_max(t_list *stack)
{
    int max;
    max = 0;
    while (stack)

    {
        if(stack->value > max)
            max =stack->value;
        stack=stack->next;
    }
    return max;
    
}
int get_min(t_list *stack)
{
    int min;
    min = stack->value;
    while (stack)
    {
        if(stack->value < min)
            min =stack->value;
        stack=stack->next;
    }
    return min;
    
}
int is_be(t_list *stack_a,int integer)
{
    while(stack_a)
    {
        if(integer==stack_a->value)
         return 1;
         stack_a=stack_a->next;
    }
    return 0;
}
void sort_3(t_list **stack)
{
    t_list *tmp;
    int max;

    max=get_max(*stack);
    tmp =* stack;
    if((*stack)->value==max)
        ra(stack);
    else if ((*stack)->next->value==max)
        rra(stack);
     if((*stack)->value > (*stack)->next->value)
          sa(stack);
     


}
void push_three(t_list **stack_a,t_list **stack_b)
{
    int push;
    push = 0;
    while(5 -push >3)
    {
       pb(stack_a,stack_b);
       push++;
    }

}
void mini_sort_5(t_list **stack_a,t_list **stack_b, int number)
{
     while(is_be(*stack_a,number))
   {
    if(number == (*stack_a)->value)
    {
        pb(stack_a,stack_b);
        break;
    }
        else if(number ==(*stack_a)->next->value)
        {
        sa(stack_a);
        pb(stack_a,stack_b);
        break;
        }
        else
        rra(stack_a);
    }
}
void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
void sort_5(t_list **stack_a,t_list **stack_b)
{
   int min;
   int max;

   min =get_min(*stack_a);
   max =get_max(*stack_a);

   mini_sort_5(stack_a,stack_b,max);
   mini_sort_5(stack_a,stack_b,min);
   sort_3(stack_a);
   pa(stack_b,stack_a);
   pa(stack_b,stack_a);
   ra(stack_a);

    
  

 }



void chismia(t_list **stack,t_list **stack_b)
{
    if(ft_lstsize(*stack)==2 && !is_sorted(*stack))
         sa(stack);
    else if(ft_lstsize(*stack)==3 && !is_sorted(*stack))
        sort_3(stack);
    else if(ft_lstsize(*stack)== 5 && !is_sorted(*stack))
    {
        sort_5(stack,stack_b);
    }
    
}