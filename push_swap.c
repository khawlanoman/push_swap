/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:21:30 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/11 11:21:34 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_stack_new(int value)
{
    t_stack *heap;

    heap = malloc(sizeof(t_stack));
    if(!heap)
        return (NULL);
    heap -> num = value;
	//heap -> index = -1;
    heap -> next = NULL;
    return (heap);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
	{
		return ;
	}
	new -> next = *lst;
	*lst = new;
}


void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*head;

	head = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (head->next)
	{
		head = head -> next;
	}
	if (head ->next == NULL)
	{
		head ->next = new;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst -> next)
	{
		lst = lst ->next;
	}
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	if (!lst)
	{
		return (0);
	}
	while (lst)
	{
		count++;
		lst = lst ->next;
	}
	return (count);
}


