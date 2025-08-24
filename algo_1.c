/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:35:19 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/24 19:26:14 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_top(s_stack *stk_a)
{
	if (stk_a -> cnt <= 1)
		return ;
	if (stk_a -> array[stk_a -> start].dest > stk_a -> array[stk_a -> start + 1].dest)
	{
		printf("swap top\n");
		swap(stk_a);
		rotate_up(stk_a);
	}
}

int	check_order(s_stack *stk_a)
{
	int	index;
	int	stk_idx;

	index = 0;
	stk_idx = (stk_a -> start + index) % stk_a -> cap;
	while (index < stk_a -> cnt)
	{
		stk_idx = (stk_a -> start + index) % stk_a -> cap;
		if (stk_a->array[stk_idx].dest > stk_a->array[(stk_idx + 1) % stk_a->cap].dest)
			return 1;
		index++;
	}
	return (0);
}
