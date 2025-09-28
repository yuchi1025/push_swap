/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:59:11 by yucchen           #+#    #+#             */
/*   Updated: 2025/09/24 16:45:33 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return ;
	node = new_node(value);
	if (!node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
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
}
