/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:05:32 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/02 17:32:50 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	last = stack->bottom;
	second->prev = NULL;
	stack->top = second;
	first->prev = last;
	first->next = NULL;
	last->next = first;
	stack->bottom = first;
	return (1);
}

void	rotate_a(t_stack *stack_a)
{
	if (rotate(stack_a))
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b)
{
	if (rotate(stack_b))
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	int	ra;
	int	rb;

	ra = rotate(stack_a);
	rb = rotate(stack_b);
	if (ra && rb)
		write(1, "rr\n", 3);
}
