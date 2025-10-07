/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:26:27 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/07 11:51:47 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_stack *stack)
{
	t_num	first;
	int		i;

	if (stack -> cnt <= 1)
		return ;
	first = stack -> array[0];
	i = 0;
	while (i < stack -> cnt - 1)
	{
		stack -> array[i] = stack -> array[i + 1];
		i++;
	}
	stack -> array[i] = first;
}

void	rotate_down(t_stack *stack)
{
	t_num	last;
	int		i;

	if (stack -> cnt <= 1)
		return ;
	last = stack -> array[stack -> cnt - 1];
	i = stack -> cnt - 1;
	while (i > 0)
	{
		stack -> array[i] = stack -> array[i - 1];
		i--;
	}
	stack -> array[i] = last;
}

void	push(t_stack *stk_a, t_stack *stk_b)
{
	t_num	top_a;

	if (!stk_a || !stk_b || stk_a->cnt == 0)
		return ;
	top_a = stk_a -> array[0];
	rotate_up(stk_a);
	stk_a -> cnt--;
	stk_b -> cnt++;
	rotate_down(stk_b);
	stk_b -> array[0] = top_a;
}

void	swap(t_stack *stack)
{
	t_num	top_a;

	if (!stack || stack->cnt <= 1)
		return ;
	top_a = stack -> array[0];
	stack -> array[0] = stack -> array[1];
	stack -> array[1] = top_a;
}
