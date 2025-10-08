/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:40:02 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/08 17:32:16 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

int	push_bottom(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (0);
	node = new_node(value);
	if (!node)
		return (0);
	if (stack->size == 0)
		stack->top = node;
	else
	{
		node->prev = stack->bottom;
		stack->bottom->next = node;
	}
	stack->bottom = node;
	stack->size++;
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	is_sorted(t_stack *stack_a)
{
	t_node	*node;

	if (stack_a->size < 2)
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
