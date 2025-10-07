/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:28:15 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/07 20:16:57 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack_a)
{
	int		i;
	int		index;
	t_node	*node;
	int		min;

	i = 0;
	index = 0;
	node = stack_a->top;
	min = node->value;
	while (node->next)
	{
		node = node->next;
		i++;
		if (node->value < min)
		{
			min = node->value;
			index = i;
		}
	}
	return (index);
}

void	bring_min_to_top(int index, t_stack *stack_a)
{
	int	i;
	int	ra_num;
	int	rra_num;

	if (index == 0)
		return ;
	i = 0;
	ra_num = index;
	rra_num = stack_a->size - index;
	if (rra_num < ra_num)
	{
		while (i < rra_num)
		{
			reverse_rotate_a(stack_a);
			i++;
		}
	}
	else
	{
		while (i < ra_num)
		{
			rotate_a(stack_a);
			i++;
		}
	}
}
