/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:59 by yucchen           #+#    #+#             */
/*   Updated: 2025/09/30 15:40:32 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static t_node	*pop_top(t_stack *src)
{
	t_node	*first;

	if (!src || src->size == 0)
		return (NULL);
	first = src->top;
	if (src->size == 1)
	{
		src->top = NULL;
		src->bottom = NULL;
	}
	else
	{
		src->top = first->next;
		src->top->prev = NULL;
	}
	src->size--;
	first->prev = NULL;
	first->next = NULL;
	return (first);
}

static void	push_front(t_stack *dst, t_node *first)
{
	if (!dst || !first)
		return ;
	if (dst->size == 0)
	{
		dst->top = first;
		dst->bottom = first;
		first->prev = NULL;
		first->next = NULL;
	}
	else
	{
		first->prev = NULL;
		first->next = dst->top;
		dst->top->prev = first;
		dst->top = first;
	}
	dst->size++;
}

static int	push(t_stack *src, t_stack *dst)
{
	t_node	*first;

	if (!src || !dst || src->size == 0)
		return (0);
	first = pop_top(src);
	if (!first)
		return (0);
	push_front(dst, first);
	return (1);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_b, stack_a))
		write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_a, stack_b))
		write(1, "pb\n", 3);
}
