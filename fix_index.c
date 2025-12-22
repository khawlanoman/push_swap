#include "push_swap.h"


int *stack_to_array(t_stack *a,int size)
{
    int *arr;
    t_stack *tmp;
    int i;

    tmp = a;
    i = 0;
    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (0);
    while (tmp)
    {
       arr[i] = tmp->num;
       i++;
       tmp = tmp->next;
    }
    return (arr);
}

void sort_array(int *arr,int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size -1)
    {
        j = 0;
        while (j < size -1)
        {
            if (arr[j] > arr[j + 1])
            {
               tmp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
} 

int get_index(int *sort, int size, int value)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (sort[i] == value)
            return (i);
        i++;
    }
    return (-1);
}

void add_index_to_node(t_stack **a)
{
    int size;
    int *sort;
    t_stack *tmp;

    tmp = *a;
    size = ft_lstsize(tmp);
    sort = stack_to_array(tmp,size);
    if (!sort)
        return ;
    sort_array(sort,size);
    while (tmp)
    {
        tmp->index = get_index(sort,size, tmp->num);
        tmp = tmp->next;
    }
    free(sort);
}