/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:30:16 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/30 14:57:41 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort2(t_stack *k)
{
	t_stack	*last;
	t_stack	*top;

	last = ft_lstlast(k);
	top = k;
	if (top->num > last->num)
		swap_a(&k);
}

void	sort3(t_stack **k)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

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
