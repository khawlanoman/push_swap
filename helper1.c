/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:20:43 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/30 13:06:44 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static void	negative_and_positive(const char *ptr, int *sign, int *i)
{
	while ((ptr[*i] >= 9 && ptr[*i] <= 13) || ptr[*i] == 32)
	{
		(*i)++;
	}
	if (ptr[*i] == '-' || ptr[*i] == '+')
	{
		if (ptr[*i] == '-')
			(*sign) *= (-1);
		(*i)++;
	}
}

int	ft_atoi(const char *ptr, int *error)
{
	int		i;
	int		sign;
	long	result;

	*error = 0;
	if (!ptr)
		return (*error = 1, 0);
	i = 0;
	sign = 1;
	result = 0;
	negative_and_positive(ptr, &sign, &i);
	if (ptr[i] < '0' || ptr[i] > '9')
		return (*error = 1, 0);
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + (ptr[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return (*error = 1, 0);
		i++;
	}
	if (ptr[i] != '\0')
		return (*error = 1, 0);
	return ((int)(result * sign));
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*arr;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	arr = malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (i < len && s[start])
	{
		arr[i++] = s[start++];
	}
	arr[i] = '\0';
	return (arr);
}
