/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:25:16 by yucchen           #+#    #+#             */
/*   Updated: 2025/09/28 17:54:08 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

// Node
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

// Stack
typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

// split_argv_utils.c
char				*join_args(int argc, char **argv);
size_t				count_tokens(char *str, char **temp, size_t *str_len);

// split_argv.c
void				ft_free_array(char **array, size_t count);
char				**split_argv(int argc, char **argv, size_t *cnt);

// number_check.c
int					is_valid_token(char **tokens, size_t *cnt);

/* // stack_utils.c
t_node				*new_node(int value);
t_stack				*init_stack(void);
void				free_stack(t_stack *stack);

// stack_operations.c
void				push_stack(t_stack *stack, int value);
int	pop_stack(t_stack *stack, int *out); */

#endif
