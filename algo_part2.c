/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:22:11 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/30 11:22:13 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_rr_or_rrr(t_stack **a, t_stack **b, t_cost *c)
{
	while (c->a > 0 && c->b > 0 && c->move_a == c->move_b)
	{
		if (c->move_a == 1)
			rotate_a_and_b(a, b);
		else
			revers_rotate_a_and_b(a, b);
		c->a--;
		c->b--;
	}
}

void	finish_a(t_stack **a, int cost, int move)
{
	while (cost-- > 0)
	{
		if (move == 1)
			rotate_a(a);
		else
			revers_rotate_a(a);
	}
}

void	finish_b(t_stack **b, int cost, int move)
{
	while (cost-- > 0)
	{
		if (move == 1)
			rotate_b(b);
		else
			revers_rotate_b(b);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best;
	int		target;
	t_cost	c;

	while (*b)
	{
		calculate_position(a);
		calculate_position(b);
		calculate_cost_b(b);
		best = find_best_cost(b, a);
		if (!best)
			break ;
		target = find_target(a, best);
		c.b = best->cost_b;
		c.move_b = best->move;
		calculate_cost_a(a, target, &c.a, &c.move_a);
		do_rr_or_rrr(a, b, &c);
		finish_a(a, c.a, c.move_a);
		finish_b(b, c.b, c.move_b);
		push_b_to_a(a, b);
	}
}

void	final_rotate(t_stack **a)
{
	int	pos;
	int	size;

	size = ft_lstsize(*a);
	pos = get_position(a, 0);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate_a(a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			revers_rotate_a(a);
	}
}
