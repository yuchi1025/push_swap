/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:04:19 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/08 15:53:51 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*temp;

	i = 2;
	str = ft_strdup(argv[1]);
	if (!str)
		return (NULL);
	while (i < argc)
	{
		temp = ft_strjoin(str, " ");
		free(str);
		if (!temp)
			return (NULL);
		str = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}

static size_t	count_loop(size_t str_len, char *temp)
{
	size_t	j;
	size_t	word_len;
	size_t	cnt;

	j = 0;
	word_len = 0;
	cnt = 0;
	while (j < str_len)
	{
		if (temp[j] != ' ' && !(temp[j] >= 9 && temp[j] <= 13))
		{
			word_len++;
			if (word_len == 1)
				cnt++;
		}
		else
			word_len = 0;
		j++;
	}
	return (cnt);
}

size_t	count_tokens(char *str, char **temp, size_t *str_len)
{
	*temp = ft_strjoin(str, " ");
	free(str);
	if (!(*temp))
		return (0);
	*str_len = ft_strlen(*temp);
	return (count_loop(*str_len, *temp));
}
