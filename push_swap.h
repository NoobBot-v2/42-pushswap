/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:30:38 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:52:34 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/printf.h"

typedef struct s_num
{
	int	val;
	int	index;
}	t_num;

typedef struct s_arr
{
	int	*array;
	int	n;
}	t_arr;

typedef struct s_rcost
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
}	t_rcost;

typedef struct s_stack
{
	int		cnt;
	int		cap;
	t_num	*array;
}	t_stack;

void	ft_init(t_stack **a, t_arr **lis, int argc, char const *argv[]);

int		get_max_num(const t_stack *s);
int		get_min_index(const t_stack *s);
void	rotate_to_top(t_stack *s, int idx);
void	radix_sort(t_stack *s1);
void	radix_controller(t_stack *s);

void	stack_create(t_stack **stack, int size, char type);
void	stack_free(t_stack **stack);
void	stack_init(t_stack *stack, char const *argv[]);
void	stack_view(t_stack *stack);

void	lis_controller(t_stack *s, t_arr *lis);
void	ft_construct_lis(t_stack *s, t_arr *tails, t_arr *prev, t_arr *LIS);
int		ft_binary_search(int *tails, int value, int n, t_stack *s);
void	ft_tails(t_stack *s, t_arr *tails, t_arr *prev);

void	algo_1(t_stack *a, t_stack *b, t_arr *lis);
void	algo_2(t_stack *a, t_stack *b);

void	ft_init_arr(t_arr **arr, int n);
void	ft_free_arr(t_arr **arr);
void	ft_free_all(t_stack **a, t_stack **b, t_arr **lis);

void	ft_consume_cost(t_stack *a, t_stack *b, t_rcost *cost);
t_rcost	ft_calculate_cost(int dest_posn, int b_posn, int a_cnt, int b_cnt);

void	ft_ra_rb(t_stack *s, int c, int n);
void	ft_rra_rrb(t_stack *s, int c, int n);
void	ft_rr(t_stack *a, t_stack *b, int n);
void	ft_rrr(t_stack *a, t_stack *b, int n);

void	rotate_up(t_stack *stack);
void	rotate_down(t_stack *stack);
void	push(t_stack *stk_a, t_stack *stk_b);
void	swap(t_stack *stack);
#endif