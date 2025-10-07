/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:33:30 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/06 16:48:31 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max)
{
	int	max_bits;

	max_bits = 0;
	while (max != 0)
	{
		max >>= 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	round;
	int	max_bits;
	int	i;
	int	j;

	round = stack_a->size;
	i = 0;
	max_bits = get_max_bits(round - 1);
	while (i < max_bits)
	{
		j = 0;
		while (j < round)
		{
			if ((stack_a->top->value >> i) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (stack_b->size != 0)
			push_a(stack_a, stack_b);
		if (is_sorted(stack_a))
			return ;
		i++;
	}
}
