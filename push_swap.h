/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:25:16 by yucchen           #+#    #+#             */
/*   Updated: 2025/10/07 13:06:10 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// Node
typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

// Stack
typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

// split_argv_utils.c
char				*join_args(int argc, char **argv);
size_t				count_tokens(char *str, char **temp, size_t *str_len);

// split_argv.c
void				ft_free_array(char **array, size_t count);
char				**split_argv(int argc, char **argv, size_t *cnt);

// number_check.c
int					is_valid_token(char **tokens, size_t cnt, int **arr);

// stack_utils.c
t_stack				*init_stack(void);
int					push_bottom(t_stack *stack, int value);
void				free_stack(t_stack *stack);
int					is_sorted(t_stack *stack_a);

// ops_swap.c
void				swap_a(t_stack *stack_a);
void				swap_b(t_stack *stack_b);
void				swap_swap(t_stack *stack_a, t_stack *stack_b);

// ops_push.c
void				push_a(t_stack *stack_a, t_stack *stack_b);
void				push_b(t_stack *stack_a, t_stack *stack_b);

// ops_rotate.c
void				rotate_a(t_stack *stack_a);
void				rotate_b(t_stack *stack_b);
void				rotate_both(t_stack *stack_a, t_stack *stack_b);

// ops_reverse_ratate.c
void				reverse_rotate_a(t_stack *stack_a);
void				reverse_rotate_b(t_stack *stack_b);
void				reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

// sort_small_utils.c
int					find_min(t_stack *stack_a);
void				bring_min_to_top(int index, t_stack *stack_a);

// sort_small.c
void				sort_small(t_stack *stack_a, t_stack *stack_b);

// radix_sort.c
void				radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif
