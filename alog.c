#include "push_swap.h"
int check(int *table,int a, int start,int end)
{
    int i;
    i = start;
    while(i <= end)
    {
        if(table[i]==a)
        return (1);
        i++;
    }
    return 0;
}
int check_all(int *table,t_list *stack, int start,int end)
{
   
  
   int s_start;
   
   s_start=start;

    while(stack)
    {
        while (start <= end)
        {
            if(stack->value==table[start])
             return 1;
            start++;
           
        }
        start=s_start;
        stack =stack->next;       
        
    }
    return 0;


}
int ft_check_max(t_list *stack,int max)
{
    while(stack)
    {
        if(max==stack->value)
        return 1;
        stack=stack->next;
    }
    return 0;
} 
int count_moves(t_list *stack,int max,int size_list)
{
    int i;
    i =0;
   while(size_list!=0)
    {
        if(max== stack->value)
         break;
        i++;
        stack=stack->next;

    }

   return i;
    
}
int  push_first_element(t_list **stack_a,t_list **stack_b,int max)
{
    int div;
    int size_list;
    int i;
    int save_result;
    
    
    size_list=ft_lstsize(*stack_b);
    div=size_list/2;
    i=count_moves(*stack_b,max,size_list);
    save_result=i;
    size_list=size_list-i;
    if(size_list> div)
    {
        while(i != 0)
        {
            rb(stack_b);
            i--;
        }
    }
    else if(size_list < div)
    {
        while(i !=0)
        {
            rrb(stack_b);
            i--;
        }
    }
        pa(stack_b,stack_a);

    return save_result;

}
void push_to_a(t_list **stack_a,t_list **stack_b,int *table,int size)
{
    int k;
    k =0;
    int index;
    index=size-1;
    int step;
    int size_list;
    
  size_list=ft_lstsize(*stack_b);
step = push_first_element(stack_a,stack_b,table[index]);
index--;
size_list=size_list-step;
while(ft_lstsize(*stack_b)!=0)
{

    while(ft_check_max(*stack_b,table[index])==1)
    {
    if(step != 0 && ft_lstlast(*stack_b)->value==table[index])
    { 
        while(step !=0)
        {
        rrb(stack_b);
        step--;
        }
        
    
        pa(stack_b,stack_a);
        index--;
    }
    else if((*stack_b)->value == table[index])
    {
     pa(stack_b,stack_a);
     index--;
    }
    else if((*stack_b)->value != table[index])
    {
        pa(stack_b,stack_a);
        ra(stack_a);
        k++;
    }
    
}
    if (ft_check_max(*stack_a,table[index])==1 && k!=0)
    {
        rra(stack_a);
        index--;
    }
 
    
}

    
//     while(ft_lstsize(*stack_b)!=0)
//     {
//         if(table[index]==(*stack_b)->value)
//         {
//           pa(stack_b,stack_a);
//           if((*stack_a)->value > (*stack_a)->next->value)
//             sa(stack_a);
//         }
//         else if(table[index-1]==(*stack_b)->value)
//         {
//             sb(stack_b);
//             pa(stack_b,stack_a);
//             k++;
//         }
//         if((*stack_b)->value >)
//         else
//         rb(stack_b);

//    }

    //   max=table[index];
    // //   if(ft_check_max(*stack_b, max)==1 || ft_check_max(*stack_a, max)==1){
    //     if(table[index]==(*stack_b)->value)
    //        pa(stack_b,stack_a);
    //     else if(table[index-1]==(*stack_b)->value)
    //     {
    //         pa(stack_b,stack_a);
    //         // if((*stack_a)->value > (*stack_a)->next->value )
    //         // {
    //         //  sa(stack_a);
    //         // }

    //     }
      
        // if((*stack_a)->value > ft_lstlast(*stack_a)->value || (*stack_a)->value > (*stack_a)->next->value)
        // {
        //  ra(stack_a);
        //  k++;
        // }
      
        
      
    //   if(ft_check_max(*stack_a,max)==1)
    //   {
    //     if(k!=0 && ft_lstlast(*stack_a)->value==max)
    //         rra(stack_a);
    //         k--;
    //   }
    //    index--;
    //     max=table[index];
 
    //   }


}
void algo_sort(t_list **stack_a,t_list **stack_b, int *table,int size)
{
    int mid;
    int offset;
    int start;
    int end;
    int i;
    int value;
    
    i=0;
    mid = (size / 2);
    offset=2;
   
    // if(size >5)
    //  offset=2;
    // if(size > 8)
    //     offset=8;
    // if(size > 50)
    //     offset=11;
    // if(size > 150)
    //     offset=16;

    start= mid - offset;
    end =mid +offset;
    if(start < 0)
    start =0;
    if(end >size)
        end=size-1;
   
    while(ft_lstsize(*stack_a)!=0)
    {
          value=(*stack_a)->value;
        
        while(check_all(table,*stack_a,start,end) != 0)
        {
            value=(*stack_a)->value;
            if(check(table,value,start,end)==1)
            { 
                pb(stack_a,stack_b);
            
            if(value < table[mid] && i == 1)
                rb(stack_b);  
                i=1; 
            }
            else
            ra(stack_a);
        }
        start-=offset;
        end+=offset;
        
        if(start < 0)
        {

       
         start =0;
         
        }
        if(end > size)
        {
            end = size-1;
           
        }

    }
     push_to_a(stack_a,stack_b,table,size);
    // if((*stack_a)->value >ft_lstlast(*stack_a)->value)
    //   ra(stack_a);
    


}