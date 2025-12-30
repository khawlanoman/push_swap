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
