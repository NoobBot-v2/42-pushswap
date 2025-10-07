/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:04:09 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/07 11:49:57 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_cost(t_rcost *cost)
{
	cost -> ra = 0;
	cost -> rra = 0;
	cost -> rb = 0;
	cost -> rrb = 0;
	cost -> rr = 0;
	cost -> rrr = 0;
	cost -> total = 0;
}

t_rcost	ft_calculate_cost(int dest_posn, int b_posn, int a_cnt, int b_cnt)
{
	t_rcost	cost;

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

void	ft_consume_cost(t_stack *a, t_stack *b, t_rcost *cost)
{
	ft_ra_rb(a, 'a', cost -> ra);
	ft_ra_rb(b, 'b', cost -> rb);
	ft_rra_rrb(a, 'a', cost -> rra);
	ft_rra_rrb(b, 'b', cost -> rrb);
	ft_rr(a, b, cost -> rr);
	ft_rrr(a, b, cost -> rrr);
	ft_init_cost(cost);
}
