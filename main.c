/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:28:20 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/03 16:43:30 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**tokens;
	size_t	cnt;
	int		*arr;
	size_t	i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	tokens = split_argv(argc, argv, &cnt);
	if (!tokens)
	{
		if (cnt == 0)
			return (0);
		return (ft_putendl_fd("Error", 2), 1);
	}
	if (!is_valid_token(tokens, cnt, &arr))
		return (ft_putendl_fd("Error", 2), ft_free_array(tokens, cnt), 1);
	
	stack_a = init_stack();
	if (!stack_a)
		return (ft_putendl_fd("Error", 2), ft_free_array(tokens, cnt),
			free(arr), 1);
	i = 0;
	while (i < cnt)
	{
		if (!push_bottom(stack_a, arr[i]))
			return (ft_putendl_fd("Error", 2), free_stack(stack_a),
				ft_free_array(tokens, cnt), free(arr), 1);
		i++;
	}
	free(arr);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		ft_free_array(tokens, cnt);
		return (0);
	}
	stack_b = init_stack();
	if (!stack_b)
		return (ft_putendl_fd("Error", 2), free_stack(stack_a),
			ft_free_array(tokens, cnt), 1);
	// TODO: call sorting functions
	if (stack_a->size <= 5)
		sort_small(stack_a, stack_b);
	
	free_stack(stack_b);
	free_stack(stack_a);
	ft_free_array(tokens, cnt);
	return (0);
}
