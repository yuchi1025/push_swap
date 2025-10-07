/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:28:20 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/07 12:17:18 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	parse_to_array(int argc, char **argv, size_t *cnt, int **arr)
{
	int		i;
	char	**tokens;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (ft_putendl_fd("Error", 2), 0);
		i++;
	}
	tokens = split_argv(argc, argv, cnt);
	if (!tokens)
		return (ft_putendl_fd("Error", 2), 0);
	if (!is_valid_token(tokens, *cnt, arr))
		return (ft_putendl_fd("Error", 2), ft_free_array(tokens, *cnt), 0);
	return (ft_free_array(tokens, *cnt), 1);
}

static int	fill_stack_a(size_t cnt, t_stack *stack_a, int *arr)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		if (!push_bottom(stack_a, arr[i]))
			return (ft_putendl_fd("Error", 2), 0);
		i++;
	}
	return (1);
}

static int	sort(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = init_stack();
	if (!stack_b)
		return (ft_putendl_fd("Error", 2), 0);
	if (stack_a->size <= 5)
		sort_small(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	return (free_stack(stack_b), 1);
}

int	main(int argc, char **argv)
{
	size_t	cnt;
	int		*arr;
	t_stack	*stack_a;

	arr = NULL;
	if (argc == 1)
		return (0);
	if (!parse_to_array(argc, argv, &cnt, &arr))
		return (1);
	stack_a = init_stack();
	if (!stack_a)
		return (ft_putendl_fd("Error", 2), free(arr), 1);
	if (!fill_stack_a(cnt, stack_a, arr))
		return (free(arr), free_stack(stack_a), 1);
	free(arr);
	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);
	if (!sort(stack_a))
		return (free_stack(stack_a), 1);
	free_stack(stack_a);
	return (0);
}
