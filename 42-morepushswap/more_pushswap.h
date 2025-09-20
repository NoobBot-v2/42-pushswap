/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_pushswap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:30:38 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/20 01:56:39 by noobdevbot2      ###   ########.fr       */
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

int	*lis_controller(s_stack *s);
#endif