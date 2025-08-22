/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:12:28 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/22 20:55:43 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void rotate_up(s_stack *stack)
{
	printf("Stack rotate up\n");
	stack -> start = (stack -> start + 1) % stack -> count;
}

void rotate_down(s_stack *stack)
{
	printf("Stack rotate down\n");
	stack -> start = (stack -> start - 1 + stack -> count) % stack -> count;
}

void push(s_stack *stk_a, s_stack *stk_b)
{
	int top_a;

	if (!stk_a || !stk_b || stk_a->count == 0)
	return;
	// Remove top from A
	top_a = stk_a->array[stk_a->start];
	stk_a->start = (stk_a->start + 1) % stk_a->capacity;
	stk_a->count--;

	// Add to top of B
	stk_b->start = (stk_b->start - 1 + stk_b->capacity) % stk_b->capacity;
	stk_b->array[stk_b->start] = top_a;
	stk_b->count++;
}

