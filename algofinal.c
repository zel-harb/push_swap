#include "push_swap.h"
 

int  research(int *table,t_list *stack, int start,int end)
{
	// int mid;
	// mid =size_stack/2;
    // // if ((*stack)->moves == 1)
	// //  return 2;// sa
	// if((*stack)->moves > mid)
	//   return 0;// move rb 
	// else
	// 	return 1;// move ra

  
 t_list *save;
 save =stack;

    while(start <= end)
    {
        while (stack)
        {
            if(stack->value==table[start])
             return (stack->moves);
             stack =stack->next;
           
        }
        start++;
        stack =save;       
        
    }
    return -1;


}

	
void push_a_to_b1(t_list **stack_a,t_list **stack_b, int *table,int size_stack)
{
    int mid;
    int offset;
    int start;
    int the_end;
    int moves;
    int i=0;

    mid = (size_stack/2) - 1;
    if(size_stack > 5)
     offset=2;
    // if(size_stack>50)
    //     offset=8;
    // if(size_stack> 150)
    //     offset= 11;
    
    start=mid - offset;
    the_end=mid +offset;

    if(start < 0)
    start =0;
    if(the_end >size_stack)
        the_end=size_stack-1;
        printf("size_stack = %d \n",size_stack);
printf("mid %d, start %d end %d\n", mid, start, the_end);
    printf("table[0] %d\n",table[0]);
   
    printf("arr[start] = %d arr[end] = %d\n", table[start], table[the_end]);
    printf("-->(end -start) %d\n",the_end-start+1);
    while((*stack_a))
    {
        while(1)
        {
           // printf("%d --> head stack_b",(*stack_b)->value);
            if((*stack_a)->value >= table[start] && (*stack_a)->value <= table[the_end])
            {
                 pb(stack_a,stack_b);
                 if((*stack_b)->value < table[mid]  &&i ==1)
                    rb(stack_b); 
                    i =1;  
                
                   
            }
            if (ft_lstsize(*stack_b) == the_end - start + 1)
                break;
            else 
            { 
                moves= research(table,*stack_a,start,the_end);
                if(moves != -1)
                {
                    if(moves > mid)
                    {
                    while( moves > 0)
                    {
                        rra(stack_a);
                        moves--;
                    }
                    }
                    else
                    {
                     while( moves >0)
                    {
                        ra(stack_a);
                        moves--;
                    }
                    }
                }
            }
                
                full_moves(stack_a);
        }
        start-=offset;
        the_end+=offset;
        if(start < 0)
            start =0;
        if(the_end > size_stack)
            the_end = size_stack - 1;
    }
    full_moves(stack_b);



    
     
}
int find_max(t_list *stack_b,int max)
{
    while(stack_b)
    {
        if (stack_b->value==max)
            return (stack_b->moves);
        stack_b=stack_b->next;
        
    }
    return (-1);

}
void first_number(t_list **stack_a,t_list **stack_b,int max)
{

    int move;
    move=find_max((*stack_b),max);
    if(move==0)
       pa(stack_b,stack_a); 
    else if(move >0 && move!=-1)
                {
                    if(move >0)
                    {
                    while( move > 0) 
                    {
                        rra(stack_a);
                        move--;
                    }
                     pa(stack_b,stack_a); 
                    }
                    else
                    {
                     while( move >0)
                    {
                        ra(stack_a);
                        move--;
                    }
                     pa(stack_b,stack_a); 
                    } 
                }
}

void push_b_to_a(t_list **stack_a,t_list **stack_b,int *table,int size)
{
    int max;
    int find;
    max =size-1;
    int k=0;
    int mid ;
   // mid =(size/2)-1;
   first_number(stack_a,stack_b,table[max]);
   full_moves(stack_b);
   max--;
   find=find_max(*stack_b,max);
   while(ft_lstsize(*stack_b))
   {
      if(ft_check_max(*stack_b, max))
      {
        if((*stack_b)->value==table[max] || (*stack_b)->value==table[max-1] )
        {
          
           if((*stack_b)->value==table[max-1])
            k++;
            pa(stack_b,stack_a);
        }
       if(k != 0)
       {
        ra(stack_a);
        full_moves(stack_b);
        find=find_max(*stack_b,max);
          if(find > ft_lstsize(*stack_b)/2)
                    {
                    while( find > 0) 
                    {
                        rrb(stack_a);
                        find--;
                    }
                     pa(stack_b,stack_a); 
                    }
                    else
                    {
                     while( find >0)
                    {
                        rb(stack_a);
                        find--;
                    }
                     pa(stack_b,stack_a); 
                    } 
       }
      }
      else if(ft_check_max(*stack_a, max))
      {
        // full_moves(stack_a);
        // find=find_max(*stack_b,max);
        if(ft_lstlast(*stack_a)->value==max)
            rra(stack_a);
      }
    //   else if(ft_check_max(*stack_b,int max))
    //   {

    //   }

       max--    ;
    //    find=find_max(*stack_b,max);


    }

  
}



void algoo_3(t_list **stack_a,t_list **stack_b, int *table,int size_stack)
{
    push_a_to_b1(stack_a,stack_b,table,size_stack);
    push_b_to_a(stack_a,stack_b,table,size_stack);

}