/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_pushswap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:30:38 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:02:58 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_num
{
	int val;
	int index;
} s_num;

typedef struct s_arr
{
	int *array;
	int n;
} s_arr;

typedef struct s_rcost
{
	int ra;
	int rra;
	int rb;
	int rrb;
	int rr;
	int rrr;
	int total;
} s_rcost;

typedef struct s_stack
{
	int cnt;
	int cap;
	s_num *array;
} s_stack;

int	get_max_num(const s_stack *s);

void	radix_sort(s_stack *s1);
void	radix_controller(s_stack *s);

void	stack_create(s_stack **stack, int size, char type);
void	stack_free(s_stack **stack);
void	stack_init(s_stack *stack, char const *argv[]);
void	stack_view(s_stack *stack);

void	lis_controller(s_stack *s, s_arr *lis);

int		ft_lis_head_idx(s_stack *s, s_arr *lis);
int		ft_lis_end_idx(s_stack *s, s_arr *lis);
void	ft_construct_lis(s_stack *s, s_arr *tails, s_arr *prev, s_arr *LIS);
int		ft_binary_search(int *tails, int value, int n, s_stack *s);
void	ft_tails(s_stack *s, s_arr *tails, s_arr *prev);

void	algo_1(s_stack *a, s_stack *b, s_arr *lis, int *grand_total);
void	algo_2(s_stack *a, s_stack *b, s_arr *lis, int *grand_total);
//void	algo_controller_2(s_stack *a, s_stack *b, s_arr *lis);
//void find_next_gap(s_stack *s, s_arr *lis);

int		get_min_index(const s_stack *s);

void	ft_init_arr(s_arr **arr, int n);
void	ft_free_arr(s_arr **arr);

void	rotate_up(s_stack *stack);
void	rotate_down(s_stack *stack);
void	push(s_stack *stk_a, s_stack *stk_b);
void	swap(s_stack *stack);
#endif