/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:49:32 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/28 xx:xx:xx by [you]            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	calculate_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_position(t_stack **stack, int index)
{
	t_stack	*tmp;
	int		pos;

	tmp = *stack;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}


void	check_and_push_to_b(t_stack **a, t_stack **b)
{
	int	size;
	int	biggest;
	int	s_biggest;
	int	t_biggest;

	size = ft_lstsize(*a);
	biggest = size - 1;
	s_biggest = size - 2;
	t_biggest = size - 3;

	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index < t_biggest)
			push_a_to_b(a, b);
		else
			rotate_a(a);
	}
	sort3(a);
}


int	find_target(t_stack **a, t_stack *b_node)
{
	t_stack	*tmp;
	int		target;

	tmp = *a;
	target = INT_MAX;
	while (tmp)
	{
		if (tmp->index > b_node->index && tmp->index < target)
			target = tmp->index;
		tmp = tmp->next;
	}
	if (target == INT_MAX)
	{
		tmp = *a;
		target = tmp->index;
		while (tmp)
		{
			if (tmp->index < target)
				target = tmp->index;
			tmp = tmp->next;
		}
	}
	return (target);
}


void	calculate_cost_b(t_stack **b)
{
	t_stack	*tmp;
	int		size;

	tmp = *b;
	size = ft_lstsize(tmp);
	while (tmp)
	{
		if (tmp->position <= size / 2)
		{
			tmp->cost_b = tmp->position;
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

t_stack	*find_best_cost(t_stack **b, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*best;
	int		min_cost;
	int		cost_a;
	int		move_a;
	int		eff_cost;

	tmp = *b;
	best = NULL;
	min_cost = INT_MAX;
	while (tmp)
	{
		int	target = find_target(a, tmp);
		calculate_cost_a(a, target, &cost_a, &move_a);

		if (move_a == tmp->move)
		{
			if (cost_a > tmp->cost_b)
				eff_cost = cost_a;
			else
				eff_cost = tmp->cost_b;
		}
		else
		{
			eff_cost = cost_a + tmp->cost_b;
		}

		if (eff_cost < min_cost)
		{
			min_cost = eff_cost;
			best = tmp;
		}
		tmp = tmp->next;
	}
	return (best);
}


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