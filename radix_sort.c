/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:33:30 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/08 11:33:22 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max)
{
	int	max_bits;

	max_bits = 0;
	while (max > 0)
	{
		max >>= 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	count;
	int	max_bits;
	int	j;

	i = 0;
	count = stack_a->size;
	max_bits = get_max_bits(count - 1);
	while (i < max_bits)
	{
		j = 0;
		while (j < count)
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
