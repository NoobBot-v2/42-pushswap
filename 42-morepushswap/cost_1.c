/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:04:09 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/06 15:09:08 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

static void	ft_init_cost(s_rcost *cost)
{
	cost -> ra = 0;
	cost -> rra = 0;
	cost -> rb = 0;
	cost -> rrb = 0;
	cost -> rr = 0;
	cost -> rrr = 0;
	cost -> total = 0;
}

s_rcost	ft_calculate_cost(int dest_posn, int b_posn, int a_cnt, int b_cnt)
{
	s_rcost cost;

	ft_init_cost(&cost);
	if (a_cnt - dest_posn < dest_posn)
		cost.rra = a_cnt - dest_posn;
	else
		cost.ra = dest_posn;
	if (b_cnt - b_posn < b_posn)
		cost.rrb = b_cnt - b_posn;
	else
		cost.rb = b_posn;
	while (cost.ra > 0 && cost.rb > 0)
	{
		cost.rr++;
		cost.ra--;
		cost.rb--;
	}
	while (cost.rra > 0 && cost.rrb > 0)
	{
		cost.rrr++;
		cost.rra--;
		cost.rrb--;
	}
	cost.total = cost.ra + cost.rra + cost.rb + cost.rrb + cost.rr + cost.rrr;
	return (cost);
}

void ft_consume_cost(s_stack *a, s_stack *b, s_rcost cost)
{
	while (cost.ra > 0)
	{
		rotate_up(a);
		cost.ra--;
	}
	while (cost.rb > 0)
	{
		rotate_up(b);
		cost.rb--;
	}
	while (cost.rra > 0)
	{
		rotate_down(a);
		cost.rra--;
	}
	while (cost.rrb > 0)
	{
		rotate_down(b);
		cost.rrb--;
	}
	while (cost.rr > 0)
	{
		rotate_up(a);
		rotate_up(b);
		cost.rr--;
	}
	while (cost.rrr > 0)
	{
		rotate_down(a);
		rotate_down(b);
		cost.rrr--;
	}
}
