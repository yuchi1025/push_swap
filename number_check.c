/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:20:09 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/03 16:43:15 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	is_number_in_range(const char *str)
{
	long long	acc;
	int			i;
	char		last_allowed;

	acc = 0;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[0] != '-')
		last_allowed = '7';
	else
		last_allowed = '8';
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (acc > 214748364 || (acc == 214748364 && (str[i] > last_allowed)))
			return (0);
		acc = acc * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

static int	has_duplicate(const int *arr, size_t cnt)
{
	size_t	i;
	size_t	j;

	if (cnt > 1)
	{
		i = 0;
		while (i < cnt)
		{
			j = i + 1;
			while (j < cnt)
			{
				if (arr[i] == arr[j])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

static int	count_rank(size_t cnt, int *arr, size_t i)
{
	size_t	j;
	int		rank;

	j = 0;
	rank = 0;
	while (j < cnt)
	{
		if (arr[i] > arr[j])
			rank++;
		j++;
	}
	return (rank);
}

static int	compress_index(size_t cnt, int **arr)
{
	size_t	i;
	int		*index;

	i = 0;
	index = (int *)malloc(cnt * sizeof(int));
	if (!index)
		return (0);
	while (i < cnt)
	{
		index[i] = count_rank(cnt, *arr, i);
		i++;
	}
	i = 0;
	while (i < cnt)
	{
		(*arr)[i] = index[i];
		i++;
	}
	return (free(index), 1);
}

int	is_valid_token(char **tokens, size_t cnt, int **arr)
{
	size_t	i;

	i = 0;
	*arr = (int *)malloc(cnt * sizeof(int));
	if (!*arr)
		return (0);
	while (i < cnt)
	{
		if (!is_number_in_range(tokens[i]))
			return (free(*arr), *arr = NULL, 0);
		(*arr)[i] = ft_atoi(tokens[i]);
		i++;
	}
	if (has_duplicate(*arr, cnt))
		return (free(*arr), *arr = NULL, 0);
	if (!compress_index(cnt, arr))
		return (free(*arr), *arr = NULL, 0);
	return (1);
}
