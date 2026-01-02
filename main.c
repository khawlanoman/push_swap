/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:21:00 by khnoman           #+#    #+#             */
/*   Updated: 2026/01/02 12:10:10 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	process_one_argument(t_stack **a, char *arg, int *pos)
{
	char	**split;
	int		j;
	int		error;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
		free_and_exit_on_error(a, NULL, split);
	j = 0;
	while (split[j])
	{
		if (!is_valid_argument(split[j], *a))
			free_and_exit_on_error(a, NULL, split);
		add_number_to_stack(a, (int)ft_atoi(split[j], &error), pos);
		j++;
	}
	free_split(split);
}

void	fill_stack_a(t_stack **a, char **argv, int argc)
{
	int	i;
	int	position;

	position = 0;
	i = 1;
	while (i < argc)
	{
		process_one_argument(a, argv[i], &position);
		i++;
	}
}

void	sort_according_to_size(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	if (size == 2)
		sort2(*a);
	else if (size == 3)
		sort3(a);
	else
	{
		check_and_push_to_b(a, b);
		push_back_to_a(a, b);
		final_rotate(a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	fill_stack_a(&a, argv, argc);
	add_index_to_node(&a);
	sort_according_to_size(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
