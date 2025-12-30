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
	write (1, "sa ", 3);
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
	write (1, "sb ", 3);
	fix_position(b);
}

void	swap_a_and_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*second;
	int		swap;

	if ((!a || !(*a) || !b || !(*b))
		|| (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2))
		return ;
	tmp = *a;
	second = tmp->next;
	swap = second->num;
	second->num = tmp->num;
	tmp->num = swap;
	swap = second->index;
	second->index = tmp->index;
	tmp->index = swap;
	tmp = *b;
	second = tmp->next;
	swap = second->num;
	second->num = tmp->num;
	tmp->num = swap;
	swap = second->index;
	second->index = tmp->index;
	tmp->index = swap;
	write(1, "ss ", 3);
	fix_position(a);
	fix_position(b);
}
