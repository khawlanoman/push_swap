/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:21:15 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/11 11:21:17 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_stack **a)
{
    t_stack *tmp = *a;
    t_stack *second;
    int swap;

     if (ft_lstsize(tmp) < 2)
    {
        write(2,"ERROR\n",6);
        return ;
    }
    second = tmp->next;
    
    swap= second->num;
    second->num = tmp->num;
    tmp->num = swap;

    swap= second->index;
    second->index = tmp->index;
    tmp->index = swap;
    write (1,"sa ",3);
}

void    swap_b(t_stack **b)
{
    t_stack *tmp = *b;
    t_stack *second;
    int swap;

    if (ft_lstsize(tmp) < 2)
    {
        write(2,"ERROR\n",6);
        return ;
    }
    second = tmp->next;

    swap= second->num;
    second->num = tmp->num;
    tmp->num = swap;

    swap= second->index;
    second->index = tmp->index;
    tmp->index = swap;
    write (1,"sb ",3);
}

void swap_a_and_b(t_stack **a, t_stack **b)
{
    t_stack *tmp_a = *a;
     t_stack *tmp_b = *b;
    t_stack *second;
    int swap;
//a
    if (ft_lstsize(tmp_a) < 2 && ft_lstsize(tmp_b) < 2)
    {
        write(2,"ERROR\n",6);
        return ;
    }
    
    second = tmp_a->next;

    swap= second->num;
    second->num = tmp_a->num;
    tmp_a->num = swap;

    swap= second->index;
    second->index = tmp_a->index;
    tmp_a->index = swap;
    //b
    second = tmp_b->next;

    swap= second->num;
    second->num = tmp_b->num;
    tmp_b->num = swap;

    swap= second->index;
    second->index = tmp_b->index;
    tmp_b->index = swap;
    write(1,"ss ",3);
}
//////////////////////push

void push_a_to_b(t_stack **a, t_stack **b)
{
    t_stack *first;
    t_stack *new_node;

    if (*a == NULL)
        return ;
    else
    {
        first = *a;
        new_node = ft_stack_new(first->num);
        new_node->index = first->index;
        ft_lstadd_front(b, new_node);
        *a = first ->next;
        free(first);
    }
    write(1,"pa ",3);
}

void push_b_to_a(t_stack **a, t_stack **b)
{
    t_stack *first;
    t_stack *new_node;

    if (*b == NULL)
        return ;
    else
    {
        first = *b;
        new_node = ft_stack_new(first->num);
        new_node->index = first->index;
        ft_lstadd_front(a, new_node);
        *b = first ->next;
        free(first);
    }    
    write(1,"pb ",3);
}
//////////////////////rotates
void rotate_a(t_stack **a)
{
    t_stack *first;
    t_stack *last;

    first = *a;
    last = ft_stack_new(first->num);
    delete_first_node(a);
    ft_lstadd_back(a,last);
     write(1,"ra ",3);
}

void rotate_b(t_stack **b)
{
    t_stack *first;
    t_stack *last;

    first = *b;
    last = ft_stack_new(first->num);
    delete_first_node(b);
    ft_lstadd_back(b,last);
     write(1,"rb ",3);
}

void    rotate_a and_b(t_stack **a, t_stack **b)
{

     t_stack *first;
    t_stack *last;

    first = *a;
    last = ft_stack_new(first->num);
    delete_first_node(a);
    ft_lstadd_back(a,last);

    first = *b;
    last = ft_stack_new(first->num);
    delete_first_node(b);
    ft_lstadd_back(b,last);
     write(1,"rr ",3);
}

//////////////////////revers rotates
void rotate_a(t_stack **a)
{
    t_stack *first;
    t_stack *last;

    last = ft_lstlast(&a);
    first = ft_stack_new(last->num);
    delete_last_node(last);
    ft_lstadd_front(a,first);
     write(1,"ra ",3);
}


