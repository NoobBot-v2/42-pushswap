/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:25:21 by jsoh@studen       #+#    #+#             */
/*   Updated: 2025/09/05 19:27:31 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Currently returns number of moves made
//Should return an instruction set
//Push 2 to b before passing
int master_control(s_stack *a, s_stack *b)
{
	int i = 0;
	int num;
	s_pair pair_a;
	s_pair pair_b;
	s_rcost cost;
	s_rcost *arr_cost;

	arr_cost = (s_rcost *)malloc(a -> cap * sizeof(s_rcost));
	if (!arr_cost)
		return (-1);
	while (a -> cnt > 0)
	{
		i = 0;
		while(i < a -> cnt)
		{
			num = a -> array[i];
			pair_a = make_pair(get_num_index(num, a), a -> cnt);
			pair_b = make_pair(number_dest_posn(num, b), b -> cnt);
			cost = final_cost(&pair_a, &pair_b);
			arr_cost[i] = cost;
			i++;
		}
		run_actions(arr_cost[lowest_cost_index(arr_cost,a -> cnt - 1)], a, b);
		pa(a, b);
	}
	while (b -> cnt > 0)
		pb(a, b);
	int rotate = get_min_index(a);
	while (rotate > 0)
	{
		ra(a);
		rotate--;
	}
	
	free(arr_cost);
	return 0;
}

void run_actions(s_rcost cost, s_stack *a, s_stack *b)
{
	while (0 < cost.ra)
	{
		ra(a);
		cost.ra--;
	}
	while (0 < cost.rb)
	{
		rb(b);
		cost.rb--;
	}
	while (0 < cost.rr)
	{
		rr(a, b);
		cost.rr--;
	}
	while (0 < cost.rra)
	{
		rra(a);
		cost.rra--;
	}
	while (0 < cost.rrb)
	{
		rrb(b);
		cost.rrb--;
	}
	while (0 < cost.rrr)
	{
		rrr(a, b);
		cost.rrr--;
	}
}
