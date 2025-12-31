/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:54:51 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/15 17:47:25 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	revers_rotate_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if ((!a || !(*a)) || (ft_lstsize(*a) < 2))
		return ;
	last = ft_lstlast(*a);
	first = ft_stack_new(last->num);
	first->index = last->index;
	delete_last_node(a);
	ft_lstadd_front(a, first);
	write(1, "rra\n", 4);
	fix_position(a);
}

void	revers_rotate_b(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if ((!b || !(*b)) || (ft_lstsize(*b) < 2))
		return ;
	last = ft_lstlast(*b);
	first = ft_stack_new(last->num);
	first->index = last->index;
	delete_last_node(b);
	ft_lstadd_front(b, first);
	write(1, "rrb\n", 4);
	fix_position(b);
}

void	revers_rotate_a_and_b(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if ((!a || !(*a) || !b || !(*b))
		|| ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2)))
		return ;
	last = ft_lstlast(*a);
	first = ft_stack_new(last->num);
	first->index = last->index;
	delete_last_node(a);
	ft_lstadd_front(a, first);
	last = ft_lstlast(*b);
	first = ft_stack_new(last->num);
	first->index = last->index;
	delete_last_node(b);
	ft_lstadd_front(b, first);
	write(1, "rrr\n", 4);
	fix_position(a);
	fix_position(b);
}
