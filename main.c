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

    a = NULL;
    b = NULL;
    i = 1;
    j = 0;
    if (argc < 2)
        return (0);
    while (i < argc)
    {
        
        char **res= ft_split(argv[i], ' ');
       j = 0;
        while (res[j])
        {
            if ((check_valid_number(res[j]) == 0 ) ||check_duplicate(a, ft_atoi(res[j],&error))== 0 )
            {
                write (1, "Error\n", 6);
                        return (0);
            }
            
            long num = ft_atoi(res[j],&error);
            if (error)
            {
                write (1, "Error\n", 6);
                        return (0);
            }
            int number = (int)num;
            new_node = ft_stack_new(number);
            ft_lstadd_back(&a,new_node);
            j++;
        }
         i++;
    }
    add_index_to_node(&a);

    if (ft_lstsize(a) == 2)
    {
        sort2(a);
    }
    if (ft_lstsize(a) == 3)
    {
        sort3(&a);
    }
    if (ft_lstsize(a) == 4)
    {
        sort4(&a, &b);
    }
    if (ft_lstsize(a) == 5)
    {
        sort5(&a,&b);
    }
    else if (ft_lstsize(a) > 5)
    {
        check_and_push_to_b(&a,&b);
    }
    
    
    //swap_a(&a);
    //push_a_to_b(&a,&b);
   //push_a_to_b(&a,&b);
    //push_a_to_b(&a,&b);
   // push_a_to_b(&a,&b);
    //push_b_to_a(&a,&b);
    //swap_b(&b);
    //swap_a_and_b(&a, &b);
    //rotate_a(&a);
    //rotate_b(&b);
    //revers_rotate_a(&a);
    //revers_rotate_b(&b);
    //revers_rotate_a_and_b(&a, &b);
   //rotate_a_and_b(&a, &b);
   printf("\nstack a\n");
    while (a)
    {
       printf(" index :%d :value:%d \n",a->index,a->num);
       a = a->next;
    }
    printf("stack b\n");
    while (b)
    {
       printf("index :%d :value:%d \n",b->index,b->num);
      b = b->next;
    }
}
