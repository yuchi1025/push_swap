/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:47:40 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/07 20:05:51 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*before_last;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->top;
	last = stack->bottom;
	before_last = last->prev;
	before_last->next = NULL;
	stack->bottom = before_last;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->top = last;
	return (1);
}

void	reverse_rotate_a(t_stack *stack_a)
{
	if (reverse_rotate(stack_a))
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	if (reverse_rotate(stack_b))
		write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
