#include "push_swap.h"

int check_valid_number(const char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int check_duplicate(t_stack *stack, int number)
{
    t_stack *current;

    current = stack;
    while (current)
    {
        if (current->num == number)
            return (0);
        current = current->next;
    }
    return (1);
}
int check_in_range(int num)
{
    if (num <= -2147483648 || num >= 2147483647)
        return (0);
    return (1);
}

////////////////
void delete_first_node(t_stack **k)
{
    t_stack  *tmp;
    
    tmp = *k;
    *k = tmp->next;
    free(tmp);

}

/////////
void delete_last_node(t_stack **k)
{
     t_stack  *tmp;
     t_stack *last;
    tmp = *a;
    while (tmp ->next != NULL)
    {
        last = tmp ;
        tmp = tmp ->next;
    }
    free(tmp);
    last -> next = NULL;
}