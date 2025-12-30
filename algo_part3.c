/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:25:53 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/30 12:19:56 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	calculate_cost_a(t_stack **a, int index, int *cost, int *move)
{
	int	pos;
	int	size;

	size = ft_lstsize(*a);
	pos = get_position(a, index);
	if (pos <= size / 2)
	{
		*cost = pos;
		*move = 1;
	}
	else
	{
		*cost = size - pos;
		*move = 0;
	}
}

int	calculate_effective_cost(int cost_a, int move_a, t_stack *b)
{
	if (move_a == b->move)
	{
		if (cost_a > b->cost_b)
			return (cost_a);
		return (b->cost_b);
	}
	return (cost_a + b->cost_b);
}

void	get_cost_data(t_stack **a, t_stack *b, t_cost *c)
{
	calculate_cost_a(a, find_target(a, b), &c->a, &c->move_a);
	c->eff_cost = calculate_effective_cost(c->a, c->move_a, b);
}

t_stack	*find_best_cost(t_stack **b, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*best;
	t_cost	c;
	int		min_cost;

	tmp = *b;
	best = NULL;
	min_cost = INT_MAX;
	while (tmp)
	{
		get_cost_data(a, tmp, &c);
		if (c.eff_cost < min_cost)
		{
			min_cost = c.eff_cost;
			best = tmp;
		}
		tmp = tmp->next;
	}
	return (best);
}
