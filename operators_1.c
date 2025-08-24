/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:12:28 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/24 19:41:09 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_up(s_stack *stack)
{
	stack -> start = (stack -> start + 1) % stack -> cap;
}

void	rotate_down(s_stack *stack)
{
	stack -> start = (stack -> start - 1 + stack -> cap) % stack -> cap;
}

void push(s_stack *stk_a, s_stack *stk_b)
{
	if (!stk_a || !stk_b || stk_a->cnt == 0)
		return;

	s_number top_a = stk_a->array[stk_a->start];
	stk_a->start = (stk_a->start + 1) % stk_a->cap;
	stk_a->cnt--;
	stk_b->start = (stk_b->start - 1 + stk_b->cap) % stk_b->cap;
	stk_b->array[stk_b->start] = top_a;
	stk_b->cnt++;
}


void swap(s_stack *stk_a)
{
	if (!stk_a || stk_a->cnt <= 1)
		return;

	int next_idx = (stk_a->start + 1) % stk_a->cap;
	s_number top_a = stk_a->array[stk_a->start];
	stk_a->array[stk_a->start] = stk_a->array[next_idx];
	stk_a->array[next_idx] = top_a;
}
