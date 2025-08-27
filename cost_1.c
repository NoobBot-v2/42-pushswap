/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh@student.42singapore.sg <jsoh@stude    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:45:10 by jsoh@studen       #+#    #+#             */
/*   Updated: 2025/08/27 20:45:10 by jsoh@studen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Distance cost to top is index or cnt - index, whichever is lower
//Preserve direction
//+1 for push cost
void	cost_zero_all(s_cost *cost)
{
	*cost = (s_cost){0};
}

//Calculates cost for bringing either max or min to the top of a stack
//Preserves direction
s_dist	cost_top(s_stack *stack)
{
	s_dist	dist;
	int		cnt;

	cnt = stack -> cnt;
	dist = (s_dist){0};
	dist.up_max = get_max_index(stack);
	dist.down_max = cnt - get_max_index(stack);
	dist.up_min = get_min_index(stack);
	dist.down_min = cnt - get_min_index(stack);
	return (dist);
}

//Check where this number would fit into the dest stack
//Need to check 2 positions each time
//Number would have to fit between 2 other numbers
//Current only checks if between
//Need to check if the new number would be a new min or new max
int number_dest_posn(const int num, const s_stack *dest_stk)
{
	int i;
	int dest;

	i = 0;
	dest = -1;
	while (i < dest_stk -> cnt - 1)
	{
		if (dest_stk -> array[i] < num && num < dest_stk -> array[i + 1])
			dest = i;
		i++;
	}
	if (dest_stk -> array[i] < num && num < dest_stk -> array[0])
		dest = i;
	return dest;
}

s_dist check_cost(const int num, const s_stack *dest_stk)
{
	s_dist cost;

	cost_zero_all(&cost);
	if (num > get_max_num(dest_stk) || num < get_min_num(dest_stk))
		cost = cost_top(dest_stk);
	else
	{
		cost.up = number_dest_posn(num, dest_stk);
		cost.down = dest_stk -> cnt - number_dest_posn(num, dest_stk);
	}
}
