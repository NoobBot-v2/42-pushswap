/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:58:39 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/05 20:23:51 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//#include "libft/libft.h"

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_rcost
{
	int ra;
	int rb;
	int rra;
	int rrb;
	int rr;
	int rrr;
	int total;
} s_rcost;

typedef struct s_costlog
{
	char *op_log;
	int log_size;
	int total_cost;
} s_costlog;

typedef struct s_pair
{
	int up;
	int down;
} s_pair;

typedef struct s_num
{
	int val;
	int order;
} s_num;

typedef struct s_stack
{
	int cnt;
	int cap;
	int *array;
	s_num *test_array;
} s_stack;

void ft_view_final_cost(s_rcost cost);
void ft_view_pair(s_pair a);
int	ft_atoi(const char *nptr);
void	stack_create(s_stack **stack, int size, char type);
void	stack_init(s_stack *stack, char const *argv[]);
void	stack_view(s_stack *stack);
void	rotate_up(s_stack *stack);
void	rotate_down(s_stack *stack);
void	push(s_stack *stk_a, s_stack *stk_b);
void	swap(s_stack *stk_a);
void ra(s_stack *a);
void rb(s_stack *b);
void rr(s_stack *a, s_stack *b);
void rra(s_stack *a);
void rrb(s_stack *b);
void rrr(s_stack *a, s_stack *b);
void pa(s_stack *a, s_stack *b);
void pb(s_stack *a, s_stack *b);
int	get_min_index(const s_stack *s_stk);
int	get_max_index(const s_stack *s_stk);
int	get_min_num(const s_stack *stack);
int	get_max_num(const s_stack *stack);
int get_num_index(const int num, const s_stack *stack);
int cost_median(s_rcost *cost, int size);
int lowest_cost_index(s_rcost *cost, int size);
int number_dest_posn(const int num, const s_stack *dest_stk);
void run_actions(s_rcost cost, s_stack *a, s_stack *b);
s_rcost check_zero(s_pair *a, s_pair *b);
s_rcost check_same_dir_cost(s_pair *a, s_pair *b);
s_rcost check_opp_cost(s_pair *a, s_pair *b);
int binary_search(int num, const s_stack *stack);
s_pair rotation_cost(int num, const s_stack *stack);
s_pair make_pair(const int index, const int cnt);
s_rcost final_cost(s_pair *a, s_pair *b);
int master_control(s_stack *a, s_stack *b);

int LIS_loop(s_stack *s);
void LIS_assign(s_stack *s, int start);
void LIS_bounds(s_stack *s);
#endif