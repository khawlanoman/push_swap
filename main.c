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

    a = NULL;
    b = NULL;
    i = 1;
    j = 0;
    if (argc < 2)
        return (0);
    while (i < argc)
    {
        char **res= ft_split(argv[i], ' ');
       
        while (res[j])
        {
            int number = ft_atoi(res[j]);
            new_node = ft_stack_new(number);
            new_node->index = j;
            ft_lstadd_back(&a,new_node);
            j++;
        }
         i++;
    }
   swap_a(&a);
   push_a_to_b(&a,&b);
   push_a_to_b(&a,&b);
 // push_b_to_a(&a,&b);
 //swap_b(&b);
 swap_a_and_b(&a, &b);
  
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
