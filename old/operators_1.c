/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:12:28 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/05 20:25:46 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void rotate_up(s_stack *stack)
{
	int first;
	int i;

	if (stack->cnt <= 1)
		return;
	first = stack->array[0];
	i = 0;
	while (i < stack -> cnt - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = first;
}

void rotate_down(s_stack *stack)
{
	int last;
	int i;

	if (stack->cnt <= 1)
		return;
	last = stack->array[stack -> cnt - 1];
	i = stack->cnt - 1;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[i] = last;
}

void push(s_stack *stk_a, s_stack *stk_b)
{
	int top_a;

	if (!stk_a || !stk_b || stk_a->cnt == 0)
		return;
	top_a = stk_a->array[0];
	rotate_up(stk_a);
	stk_a->cnt--;
	stk_b->cnt++;
	rotate_down(stk_b);
	stk_b->array[0] = top_a;
}

void swap(s_stack *stack)
{
	int top_a;

	if (!stack || stack->cnt <= 1)
		return;
	top_a = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = top_a;
	printf("swap\n");
}
