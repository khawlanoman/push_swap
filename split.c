/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:21:59 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/15 16:57:42 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	found;
	int	count;

	i = 0;
	found = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && found == 0)
		{
			count++;
			found = 1;
		}
		if (s[i] == c && found == 1)
			found = 0;
		i++;
	}
	return (count);
}

static void	free_word(char **arr, int k)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < k)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	check_arr(char **arr, int k)
{
	if (!arr[k])
	{
		free_word(arr, k);
		return (0);
	}
	return (1);
}

static int	ft_all_copy(char const *s, char **arr, char c)
{
	int	i;
	int	start;
	int	end;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (end > start)
		{
			arr[k] = ft_substr(s, start, (end - start));
			if (!check_arr(arr, k))
				return (0);
			k++;
		}
	}
	arr[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_all_copy(s, arr, c))
		return (NULL);
	return (arr);
}
