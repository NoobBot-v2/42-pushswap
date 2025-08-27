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

typedef struct s_stack
{
	int cnt;
	int cap;
	int *array;
} s_stack;

typedef struct s_dist
{
	int up_max;
	int down_max;
	int up_min;
	int down_min;
	int up;
	int down;
} s_dist;

typedef struct s_cost
{
	int pa;
	int pb;
	int sa;
	int sb;
	int ss;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	int total;
} s_cost;

int	ft_atoi(const char *nptr);
void	stack_create(s_stack **stack, int size, char type);
void	stack_init(s_stack *stack, char const *argv[]);
void	stack_view(s_stack *stack);
void	rotate_up(s_stack *stack);
void	rotate_down(s_stack *stack);
void	push(s_stack *stk_a, s_stack *stk_b);
void	swap(s_stack *stk_a);
int	get_min_index(s_stack *s_stk);
int	get_max_index(s_stack *s_stk);
int	get_min_num(s_stack *stack);
int	get_max_num(s_stack *stack);
int number_dest_posn(const int num, const s_stack *dest_stk);
#endif