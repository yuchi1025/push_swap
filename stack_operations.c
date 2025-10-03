/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:11 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/01 16:52:05 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_bottom(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (0);
	node = new_node(value);
	if (!node)
		return (0);
	node->next = NULL;
	if (stack->size == 0)
	{
		node->prev = NULL;
		stack->top = node;
	}
	else
	{
		node->prev = stack->bottom;
		stack->bottom->next = node;
	}
	stack->bottom = node;
	stack->size++;
	return (1);
}

/* int	push_stack(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (0);
	node = new_node(value);
	if (!node)
		return (0);
	node->prev = NULL;
	node->next = stack->top;
	if (stack->top)
		stack->top->prev = node;
	stack->top = node;
	if (stack->size == 0)
		stack->bottom = node;
	stack->size++;
	return (1);
}

int	pop_stack(t_stack *stack, int *out)
{
	t_node	*first;

	if (!stack || stack->size == 0)
		return (0);
	first = stack->top;
	if (out)
		*out = first->value;
	stack->top = first->next;
	free(first);
	stack->size--;
	return (1);
} */
