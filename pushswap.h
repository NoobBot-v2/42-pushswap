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

typedef struct s_number
{
	int num;
	double dest;
} s_number;

typedef struct s_stack
{
	int start;
	int cnt;
	int cap;
	s_number *array;
} s_stack;

int	ft_atoi(const char *nptr);
void	stack_create(s_stack **stack, int size, char type);
void	stack_init(s_stack *stack, char const *argv[]);
void	stack_view(s_stack *stack);
void	stack_dest(s_stack *s_stk);
void	rotate_up(s_stack *stack);
void	rotate_down(s_stack *stack);
void	push(s_stack *stk_a, s_stack *stk_b);
void	swap(s_stack *stk_a);
int	get_min(s_stack *s_stk);
int	get_max(s_stack *s_stk);
double	normalize(int min, int max, int num, int cap);
#endif