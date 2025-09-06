/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:26:29 by jsoh@studen       #+#    #+#             */
/*   Updated: 2025/08/31 17:54:35 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static s_rcost calculate_up_dir(int a, int b)
{
	s_rcost cost;

	cost = (s_rcost){0};
	if (a >= b)
	{
		cost.rr = b;
		cost.ra = a - b;
		cost.total = cost.rr + cost.ra;
	}
	else if (b > a)
	{
		cost.rr = a;
		cost.rb = b - a;
		cost.total = cost.rr + cost.rb;
	}
	return (cost);
}

static s_rcost calculate_down_dir(int a, int b)
{
	s_rcost cost;

	cost = (s_rcost){0};
	if (a >= b)
	{
		cost.rrr = b;
		cost.rra = a - b;
		cost.total = cost.rrr + cost.rra;
	}
	else if (b > a)
	{
		cost.rrr = a;
		cost.rrb = b - a;
		cost.total = cost.rrr + cost.rrb;
	}
	return (cost);
}

// Case 0
s_rcost check_same_dir_cost(s_pair *a, s_pair *b)
{
	s_rcost cost_up;
	s_rcost cost_down;

	cost_up = calculate_up_dir(a->up, b->up);
	cost_down = calculate_down_dir(a->down, b->down);
	if (cost_up.total <= cost_down.total)
		return (cost_up);
	else
		return (cost_down);
}
// Case 1
s_rcost check_opp_cost(s_pair *a, s_pair *b)
{
	s_rcost cost;

	cost = (s_rcost){0};
	if ((a->up + b->down) <= (a->down + b->up))
	{
		cost.ra = a->up;
		cost.rrb = b->down;
		cost.total = cost.ra + cost.rrb;
	}
	else
	{
		cost.rb = b->up;
		cost.rra = a->down;
		cost.total = cost.rb + cost.rra;
	}
	//printf("rrb:%-3i\n",cost.rrb);
	return (cost);
}
