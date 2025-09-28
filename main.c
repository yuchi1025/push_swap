/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:28:20 by yucchen           #+#    #+#             */
/*   Updated: 2025/09/28 17:54:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// Instructions must be separated by a ’\n’ and nothing else.
/* In case of error,
	it must display "Error" followed by an ’\n’ on the standard error.
Errors include, for example: some arguments not being integers, some arguments
exceeding the integer limits, and/or the presence of duplicates. */

/* int	main(void)
{
	t_stack	*stack;
	int		value;

	stack = init_stack();
	push_stack(stack, 10);
	push_stack(stack, 20);
	push_stack(stack, 30);
	if (pop_stack(stack, &value))
		ft_printf("pop -> %d\n", value);
	if (pop_stack(stack, &value))
		ft_printf("pop -> %d\n", value);
	if (pop_stack(stack, &value))
		ft_printf("pop -> %d\n", value);
	if (!pop_stack(stack, &value))
		ft_printf("pop on empty -> fail\n");
	free_stack(stack);
	return (0);
	// TODO: parse arguments & push to stack
	// TODO: call sorting functions
	// If no parameters are specified, the program must not display anything
	// and should return to the prompt.
} */

int	main(int argc, char **argv)
{
	char	**tokens;
	size_t	cnt;

	tokens = split_argv(argc, argv, &cnt);
	if (!tokens)
		return (1);
	if (!is_valid_token(tokens, &cnt))
		return (ft_free_array(tokens, cnt), 1);
	else
		ft_printf("Success\n");
	ft_free_array(tokens, cnt);
	return (0);
}
