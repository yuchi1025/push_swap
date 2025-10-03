/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:45:23 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/01 16:54:23 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack *stack_a)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	if (stack_a->top->value > stack_a->top->next->value)
		swap_a(stack_a);
}

static void	sort_3(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	if (!stack_a || stack_a->size < 3)
		return ;
	top = stack_a->top->value;
	middle = stack_a->top->next->value;
	bottom = stack_a->bottom->value;
	if (top > middle && top < bottom)
		swap_a(stack_a);
	else if (top > middle && middle > bottom)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (top > middle && top > bottom && middle < bottom)
		rotate_a(stack_a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (top < middle && top > bottom)
		reverse_rotate_a(stack_a);
}

static void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	if (!stack_a || stack_a->size != 4 || is_sorted(stack_a))
		return ;
	index = find_min(stack_a);
	bring_min_to_top(index, stack_a);
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
}

static void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	if (!stack_a || stack_a->size != 5 || is_sorted(stack_a))
		return ;
	index = find_min(stack_a);
	bring_min_to_top(index, stack_a);
	push_b(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	if (!stack_a || size < 2)
		return ;
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else
		sort_5(stack_a, stack_b);
}
