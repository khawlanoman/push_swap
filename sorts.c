/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:30:16 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/17 15:30:18 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void sort2(t_stack *k)
{
    t_stack *last;
    t_stack *top;

    last = ft_lstlast(k);
    top = k;
    if (top->num > last->num)
        swap_a(&k);
}

void sort3(t_stack **k)
{
    t_stack *a;
    t_stack *b;
    t_stack *c;

    a = *k;
    b = a->next;
    c = b->next;

    if (a->num > b->num && b->num < c->num && a->num < c->num)
        swap_a(k);
    else if (a->num > b->num && b->num > c->num)
    {
        swap_a(k);
        revers_rotate_a(k);
    }
    else if (a->num > b->num && b->num < c->num && a->num > c->num)
        rotate_a(k);
    else if (a->num < b->num && b->num > c->num && a->num < c->num)
    {
        swap_a(k);
        rotate_a(k);
    }
    else if (a->num < b->num && b->num > c->num && a->num > c->num)
       revers_rotate_a(k);
}


void sort4(t_stack **k, t_stack **l)
{
    t_stack *a;
    
    a = *k;
    if (a->index == 0)
    push_a_to_b(k,l);
    else if (a->next->index == 0)
    {
        swap_a(k);
        push_a_to_b(k,l);
    }
    else if (a->next->next->index == 0)
    {
        revers_rotate_a(k);
       revers_rotate_a(k);
       push_a_to_b(k,l);
    }
    else if (a->next->next->next->index == 0)
    {
       revers_rotate_a(k);
       push_a_to_b(k,l);
    }
    sort3(k);
    push_b_to_a(k,l);
}

void check_index(t_stack **k, t_stack **l, int id)
{
     t_stack *a;

    a = *k;
    if (a->index == id)
        push_a_to_b(k,l);
    else if (a->next->index == id)
    {
        swap_a(k);
        push_a_to_b(k,l);
    }
    else if (a->next->next->index == id)
    {
       revers_rotate_a(k);
       revers_rotate_a(k);
       revers_rotate_a(k);
       push_a_to_b(k,l);
    }
    else if (a->next->next->next->index == id)
    {
       revers_rotate_a(k);
       revers_rotate_a(k);
       push_a_to_b(k,l);
    }
    else if (a->next->next->next->next->index == id)
    {
       revers_rotate_a(k);
       push_a_to_b(k,l);
    }
}
void sort5(t_stack **k, t_stack **l)
{
    check_index(k,l,0);
    check_index(k,l,1);
    sort3(k);
    push_b_to_a(k,l);
    push_b_to_a(k,l);
}