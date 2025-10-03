/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:41:24 by yucchen           #+#    #+#             */
/*   Updated: 2025/09/29 15:34:36 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_free_array(char **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	store_tokens(size_t str_len, char *temp, char **tokens)
{
	size_t	j;
	size_t	word_len;
	size_t	k;

	j = 0;
	word_len = 0;
	k = 0;
	while (j < str_len)
	{
		if (temp[j] != ' ' && !(temp[j] >= 9 && temp[j] <= 13))
			word_len++;
		else
		{
			if (word_len > 0)
			{
				tokens[k] = ft_substr(temp, j - word_len, word_len);
				if (!tokens[k])
					return (ft_free_array(tokens, k), 0);
				word_len = 0;
				k++;
			}
		}
		j++;
	}
	return (1);
}

static char	**split_tokens(size_t cnt, char **temp, size_t *str_len)
{
	char	**tokens;

	tokens = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!tokens)
		return (NULL);
	if (store_tokens(*str_len, *temp, tokens))
	{
		tokens[cnt] = NULL;
		return (tokens);
	}
	return (NULL);
}

char	**split_argv(int argc, char **argv, size_t *cnt)
{
	char	*str;
	char	*temp;
	size_t	str_len;
	char	**tokens;

	*cnt = 1;
	str = join_args(argc, argv);
	if (!str)
		return (NULL);
	*cnt = count_tokens(str, &temp, &str_len);
	if (*cnt == 0)
		return (free(temp), NULL);
	tokens = split_tokens(*cnt, &temp, &str_len);
	if (!tokens)
		return (free(temp), NULL);
	free(temp);
	return (tokens);
}
