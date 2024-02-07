#include "push_swap.h"

int check_double(char **argv,int argc)
{
    int i ;
    int j;
    i =1;
    j =2;
   while(i < argc)
   {
    while(j < argc)
    {
        if(ft_atoi(argv[i])==ft_atoi(argv[j]))
        {
            ft_putstr_fd("Error\n",1);
         return 1;
        }
         j++;
    }
    i++;
    j=i+1;
   }
   return 0;
    
}

int check_intervalle(char **argv,int argc)
{
    int i;

    i=1;
    while(i < argc)
    {
       
        if(ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
        {
            ft_putstr_fd("Error\n",1);
            return 1;
        }
        i++;
    }
    return 0;
}

int check_non_number(char **argv,int argc)
{
    int i;
    int j;

    i=1;
    while(i < argc)
    {
        j=0;
        while(argv[i][j])
        {
            if((argv[i][j] < '0'  || argv[i][j] > '9') && argv[i][j] !='-')
            {
                ft_putstr_fd("Error\n",1);
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int check_num_is_valid(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_error(char **argv,int argc)
{
   
    if(check_non_number(argv,argc))
        return 1;
    if(check_double(argv,argc))
        return 1;
    if(check_intervalle(argv,argc))
        return 1;
    if(check_non_number(argv,argc))
        return 1;
    return 0;   
}

