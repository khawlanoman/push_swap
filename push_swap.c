#include "push_swap.h"

t_stack *ft_stack_new(int value)
{
    t_stack *heap;

    heap = malloc(sizeof(t_stack));
    if(!heap)
        return (NULL);
    heap -> num = value;
    heap -> index = -1;
    heap -> next = NULL
    return (heap);
}

t_stack *ft_stack_add_back(int value, t_stack *node)
{
    t_stack *heap;

    heap = malloc(sizeof(t_stack));
    if(!heap)
        return (NULL);
    heap -> num = value;
    heap -> index = -1;
    heap -> 
}