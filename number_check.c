/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:20:09 by yucchen           #+#    #+#             */
/*   Updated: 2025/09/28 19:01:20 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	is_number_in_range(char *str)
{
	long long	acc;
	int			i;
	char		temp;

	acc = 0;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (str[0] != '-')
		temp = '7';
	else
		temp = '8';
	while (str[i])
	{
		if (acc > 214748364 || (acc == 214748364 && (str[i] > temp)))
			return (0);
		acc = acc * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

int	has_duplicate(const int *arr, size_t cnt)
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

int	is_valid_token(char **tokens, size_t *cnt)
{
	size_t	i;
	size_t	j;
	int *arr;

	i = 0;
	arr = (int *)malloc(*cnt * sizeof(int));
	if (!arr)
		return (0);
	while (i < *cnt)
	{
		j = 0;
		if (tokens[i][j] == '+' || tokens[i][j] == '-')
			j++;
		if (tokens[i][j] == '\0')
			return (free(arr), 0);
		while (tokens[i][j])
		{
			if (tokens[i][j] < '0' || tokens[i][j] > '9')
				return (free(arr), 0);
			j++;
		}
		if (!is_number_in_range(tokens[i]))
			return (free(arr), 0);
		arr[i] = ft_atoi(tokens[i]);
		i++;
	}
	if (has_duplicate(arr, *cnt))
		return (free(arr), 0);
	return (free(arr), 1);
}
