/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:21:15 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/15 17:30:52 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_a(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*second;
	int		swap;

	if ((!a || !(*a)) || (ft_lstsize(*a) < 2))
		return ;
	tmp = *a;
	second = tmp->next;
	swap = second->num;
	second->num = tmp->num;
	tmp->num = swap;
	swap = second->index;
	second->index = tmp->index;
	tmp->index = swap;
	write (1, "sa\n", 3);
	fix_position(a);
}

void	swap_b(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*second;
	int		swap;

	if ((!b || !(*b)) || ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	second = tmp->next;
	swap = second->num;
	second->num = tmp->num;
	tmp->num = swap;
	swap = second->index;
	second->index = tmp->index;
	tmp->index = swap;
	write (1, "sb\n", 3);
	fix_position(b);
}

static void	swap_a_for_ss(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*second;
	int		swap;

	tmp = *a;
	second = tmp->next;
	swap = second->num;
	second->num = tmp->num;
	tmp->num = swap;
	swap = second->index;
	second->index = tmp->index;
	tmp->index = swap;
}

static void	swap_b_for_ss(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*second;
	int		swap;

	tmp = *b;
	second = tmp->next;
	swap = second->num;
	second->num = tmp->num;
	tmp->num = swap;
	swap = second->index;
	second->index = tmp->index;
	tmp->index = swap;
}

void	swap_a_and_b(t_stack **a, t_stack **b)
{
	if ((!a || !(*a) || !b || !(*b))
		|| (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2))
		return ;
	swap_a_for_ss(a);
	swap_b_for_ss(b);
	write(1, "ss\n", 3);
	fix_position(a);
	fix_position(b);
}
