/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:49:32 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/19 15:49:33 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void check_and_push_to_b(t_stack **a,t_stack **b)
{
    int biggest;
    int s_biggest;
    int t_biggest;
    int size;

    size = ft_lstsize(*a);
    biggest = size - 1;
    s_biggest = size - 2;
    t_biggest = size - 3;

    while (ft_lstsize(*a) > 3)
    {
        if (((*a)->index < t_biggest && (*a)->index < s_biggest) && (*a)->index < biggest )
        {
            push_a_to_b(a,b);
        }
        else
        {
            rotate_a(a);
        }
    }
    sort3(a);
}

int find_target(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int best_index;

    tmp = *a;
    best_index = tmp->index;
    while (tmp)
    {
       if ((tmp->index > (*b)->index) && (tmp->index < best_index))
       {
            best_index = tmp->index;
       }
       tmp = tmp->next;
    }
    return (best_index);
}

void calculate_cost_b(t_stack **b)
{
    t_stack *tmp;
    int size;

    tmp = *b;
    size = ft_lstsize(tmp);
    while (tmp)
    {
        if (tmp->position <= size/2)
        {
           tmp->cost_b =tmp->position;
           tmp->move = 1;
        }
        else
        {
            tmp->cost_b = size - tmp->position;
             tmp->move = 0;
        }
        tmp = tmp->next;
    }
}

int find_best_cost(t_stack **b)
{
    t_stack *tmp;
    int best_cost;

    tmp = *b;
    best_cost = tmp->cost_b;
    while (tmp)
    {
        if (tmp->cost_b < best_cost)
        {
            best_cost = tmp->cost_b;
        }
        tmp = tmp->next;
    }
    return (best_cost);
}

void move_it_to_top(t_stack **b,t_stack **a)
{
    t_stack *tmp;
    //int best_cost;
    int num_move;

    tmp = *b;
    num_move = tmp->cost_b;
    //best_cost = find_best_cost(b);
    while ( num_move > 0)
    {
       if (tmp->move == 0)
       {
            rotate_b(b);
       }
       else if (tmp->move == 1)
       {
            revers_rotate_b(b);
       }
       num_move--;
    }
    push_b_to_a(a,b);
}