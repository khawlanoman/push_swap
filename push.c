/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:53:09 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/15 17:54:02 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*new_node;

	if ((!a || !(*a)) || (ft_lstsize(*a) < 1))
		return ;
	first = *a;
	new_node = ft_stack_new(first->num);
	new_node->index = first->index;
	ft_lstadd_front(b, new_node);
	*a = first ->next;
	free(first);
	write(1, "pb\n", 3);
	fix_position(a);
	fix_position(b);
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*new_node;

	if ((!b || !(*b)) || (ft_lstsize(*b) < 1))
		return ;
	first = *b;
	new_node = ft_stack_new(first->num);
	new_node->index = first->index;
	ft_lstadd_front(a, new_node);
	*b = first ->next;
	free(first);
	write(1, "pa\n", 3);
	fix_position(a);
	fix_position(b);
}
