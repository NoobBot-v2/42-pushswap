/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:58:39 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/24 19:23:17 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

typedef struct s_pair
{
	int up;
	int down;
} s_pair;

typedef struct s_stack
{
	int cnt;
	int cap;
	int *array;
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
int	get_min_index(const s_stack *s_stk);
int	get_max_index(const s_stack *s_stk);
int	get_min_num(const s_stack *stack);
int	get_max_num(const s_stack *stack);
int get_number_index(const int num, const s_stack *stack);
int number_dest_posn(const int num, const s_stack *dest_stk);
s_rcost check_zero(s_pair *a, s_pair *b);
s_rcost check_same_dir_cost(s_pair *a, s_pair *b);
s_rcost check_opp_cost(s_pair *a, s_pair *b);
int ft_binary_search(int num, const s_stack *stack);
s_pair ft_rotation_cost(int num, const s_stack *stack);
s_pair ft_unsorted_rotation_cost(int num, const s_stack *stack);
s_pair get_up_down(const int index, const int cnt);
s_rcost ft_final_cost(s_pair *a, s_pair *b);
#endif