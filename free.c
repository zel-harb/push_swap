#include "push_swap.h"


void freeList(t_list* head) {

    t_list *temp;

    while (head != NULL) 
	{
        temp = head;
        head = head->next;
        free(temp);
    }
}
