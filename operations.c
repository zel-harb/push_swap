#include <stdio.h>
#include "push_swap.h"

int  swap(t_list *stack_a)
{
    t_list *tmp;
    int val;
    int val2;
  if (ft_lstsize(stack_a) < 2)
		return (-1);
    tmp=stack_a;
    val =tmp->value;
    tmp=tmp->next;
    val2=tmp->value;
    tmp=stack_a;
    tmp->value=val2;
    tmp=tmp->next;
    tmp->value=val;
    return 0;
}
int  sa(t_list *stack_a)
{
    if(swap(stack_a)==-1)
      return (-1);
    ft_putstr_fd("sa\n",1);
    return (0);
}
int sb(t_list *stack_b)
{
    if(swap(stack_b)==-1)
        return (-1);
    ft_putstr_fd("sb\n",1);
    return (0);
}
int ss(t_list *stack_a,t_list *stack_b)
{
    if(swap(stack_a) == -1 || swap(stack_b)== -1)
        return(-1);
    ft_putstr_fd("ss\n",1);
    return(0);
}
int rotate(t_list *stack)
{
    t_list *tmp;
    t_list *liste;
    int val;
    int val2;

    if (ft_lstsize(stack) < 2)
		return (-1);
    tmp=stack;
    liste=ft_lstlast(tmp);
    val2 =liste->value;
    val=stack->value;
    liste->value=val;
    stack->value=val2;
    return (0);
    

}
int  ra(t_list *stack_a)
{
    if(rotate(stack_a)==-1)
      return (-1);
    ft_putstr_fd("ra\n",1);
    return (0);
}
int  rb(t_list *stack_b)
{
    if(rotate(stack_b)==-1)
      return (-1);
    ft_putstr_fd("rb\n",1);
    return (0);
}

//int ss(t_list *stack_a,t_list *stack_b)
int rr(t_list *stack_a,t_list *stack_b)
{
    rotate(stack_a);
	rotate(stack_b);
    ft_putstr_fd("rr\n",1);
    return(0);
}
int	reverseRotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}
int	rra(t_list *stack_a)
{
	if (reverseRotate(&stack_a) == -1)
		return (-1);
	 //ft_putstr_fd("rra", 1);
	return (0);
}






