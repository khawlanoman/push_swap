/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:21:00 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/11 11:21:02 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *new_node;
    int i;
    int j;
    int error;
    int p;
    a = NULL;
    b = NULL;
    i = 1;
    j = 0;
    p = 0;
    if (argc < 2)
        return (0);
    while (i < argc)
    {
        
        char **res= ft_split(argv[i], ' ');
        if (!res || !res[0])
        {
            write (2, "Error\n", 6);
            return (0);
        }
        
       j = 0;
        while (res[j])
        {
            long num = ft_atoi(res[j],&error);
            if (error || (check_valid_number(res[j]) == 0 ) ||check_duplicate(a, ft_atoi(res[j],&error))== 0 )
            {
                write (2, "Error\n", 6);
                        return (0);
            }
            int number = (int)num;
            new_node = ft_stack_new(number);
            new_node->position = p++;
            ft_lstadd_back(&a,new_node);
            j++;
        }
        free_split(res);
        i++;
    }
    add_index_to_node(&a);

   if (ft_lstsize(a) == 2)
        sort2(a);
   else if (ft_lstsize(a) == 3)
        sort3(&a);
    else
    {
        check_and_push_to_b(&a, &b);  
        push_back_to_a(&a, &b); 
        final_rotate(&a);
    }
   /* printf("\nstack a\n");
    while (a)
    {
        printf(" index :%d :value:%d position:%d\n",a->index,a->num,a->position);
        a = a->next;
    }
    printf("stack b\n");
    while (b)
    {
        printf("index :%d :value:%d position:%d cost:%d move: %d\n",b->index,b->num,b->position, b->cost_b, b->move);
        b = b->next;
    }*/
    free_stack(&a);
    free_stack(&b);
    return (0);
}
