/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:51:40 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/15 17:38:57 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if ((!a || !(*a)) || (ft_lstsize(*a) < 2))
		return ;
	first = *a;
	last = ft_stack_new(first->num);
	last->index = first->index;
	delete_first_node(a);
	ft_lstadd_back(a, last);
	write(1, "ra\n", 3);
	fix_position(a);
}

void	rotate_b(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if ((!b || !(*b)) || (ft_lstsize(*b) < 2))
		return ;
	first = *b;
	last = ft_stack_new(first->num);
	last->index = first->index;
	delete_first_node(b);
	ft_lstadd_back(b, last);
	write(1, "rb\n", 3);
	fix_position(b);
}

void	rotate_a_and_b(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if ((!a || !(*a) || !b || !(*b))
		|| (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2))
		return ;
	first = *a;
	last = ft_stack_new(first->num);
	last->index = first->index;
	delete_first_node(a);
	ft_lstadd_back(a, last);
	first = *b;
	last = ft_stack_new(first->num);
	last->index = first->index;
	delete_first_node(b);
	ft_lstadd_back(b, last);
	write(1, "rr\n", 3);
	fix_position(a);
	fix_position(b);
}
