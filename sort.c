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
    min = 0;
    while (stack)
    {
        if(stack->value < min)
            min =stack->value;
        stack=stack->next;
    }
    return min;
    
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
// void sort_5(t_list **stack_a,t_list **stack_b)
// {
//     push_three(stack_a,stack_b);
//         sort_3(stack_a);
//      pa(stack_b,stack_a);
//     if((*stack_a)->value > ft_lstlast(*stack_a)->value)
//          ra(stack_a);
//    else if((*stack_a)->value > (*stack_a)->next->value)
//         sa(stack_a); 
//     if((*stack_b)->value > (*stack_a)->value && (*stack_b)->value < ft_lstlast(*stack_a)->value  )
//       ra(stack_a);
//      pa(stack_b,stack_a);
//     if((*stack_a)->value > ft_lstlast(*stack_a)->value)
//         ra(stack_a);
//     else if((*stack_a)->value > (*stack_a)->next->value)
//       sa(stack_a);
    
  

//  }
// void sort_5(t_list **stack_a,t_list **stack_b)
// {
//     int min;
//     int max;

//     min=get_min(*stack_a);
//     max=get_max(*stack_a);
  
//     if((*stack_a)->value == max)
//         pa(stack_a,stack_b);
//     else if((*stack_a)->next->value == max)
//     {
//         sa(stack_a);
//         pa(stack_a,stack_b);
//     }
//     else if (ft_lstlast(*stack_a)->value == max)
//     {
//         rra(stack_a);
//        pa(stack_a,stack_b);
//     }
//     else 
//       pa(stack_a,stack_b);
//   pa(stack_a,stack_b);
//   sort_3(stack_a);
//   if((*stack_b)->value == min)
//         pb(stack_b,stack_a);
//     else 
//       pb(stack_b,stack_a);
//     if(!is_sorted(*stack_a))


   
// }


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