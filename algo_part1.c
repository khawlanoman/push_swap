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
