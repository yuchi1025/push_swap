/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:22:18 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/07 18:13:42 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
	return (1);
}

void	swap_a(t_stack *stack_a)
{
	if (swap(stack_a))
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b)
{
	if (swap(stack_b))
		write(1, "sb\n", 3);
}

void	swap_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
