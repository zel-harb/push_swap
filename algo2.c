#include "push_swap.h"

void push_to_b(t_list **stack_a,t_list **stack_b,int *table,int size)
{
    int mid;
    int offset;
    int start;
    int end;

    mid=size/2 ;
    offset=2;
    start=mid - offset;
    end = mid + offset;
   


    // printf("mid %d, start %d end %d\n", mid, start, end);
    // printf("table[0] %d\n",table[0]);
    // while(ft_lstsize(*stack_a)!=0)
    // {
    //printf("arr[start] = %d arr[end] = %d\n", table[start], table[end]);
    while((*stack_a))
    {
    while(ft_lstsize(*stack_b) <= (end - start-1))
    {
        if((*stack_a)->value >= table[start] && (*stack_a)->value <= table[end])
        {
            pb(stack_a,stack_b);
            if((*stack_b)->value < table[mid] )
                rb(stack_b); 
       }
        else
                ra(stack_a);
    }
        start-=offset;
        end+=offset;
        if(start < 0)
            start =0;
        if(end > size)
            end = size - 1;

   }
}



void algo_1(t_list **stack_a,t_list **stack_b,int *table,int size)
{
    push_to_b(stack_a,stack_b,table,size);
    //pb(stack_a,stack_b);
}