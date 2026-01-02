/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:11:09 by khnoman           #+#    #+#             */
/*   Updated: 2026/01/02 12:07:11 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_split(char **res)
{
	int	i;

	i = 0;
	if (!res)
		return ;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*n;

	if (!s)
		return ;
	tmp = *s;
	while (tmp)
	{
		n = tmp->next;
		free(tmp);
		tmp = n;
	}
	*s = NULL;
}
