/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:28:15 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/01 13:29:02 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	t_node	*node;

	if (!stack_a || stack_a->size < 2)
		return (1);
	node = stack_a->top;
	while (node->next)
	{
		if (node->next->value < node->value)
			return (0);
		node = node->next;
	}
	return (1);
}

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
