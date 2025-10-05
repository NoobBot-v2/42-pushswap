/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:55:03 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:10:24 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

static int	home_min(s_stack *s)
{
	int	i;

	i = 0;
	while (s -> array[0].index != 0)
	{
		rotate_up(s);
		i++;
	}
	return (i--);
}

static void	original_idx(s_stack *s, int offset)
{
	while (offset > 0)
	{
		rotate_down(s);
		offset--;
	}
}

static int	ft_mod_binary_search(s_stack *s, int value)
{
	int	start;
	int	end;
	int	mid;
	int	offset;

	offset = 0;
	start = 0;
	end = s -> cnt - 1;
	offset = home_min(s);
	while (start <= end)
	{
		mid = (end + start) / 2;
		if (value >= s -> array[mid].index)
			start = mid + 1;
		else
			end = mid - 1;
	}
	original_idx(s,offset);
	return ((start + offset) % s -> cnt);
}

/* typedef struct s_rcost
{
	int ra;
	int rra;
	int rb;
	int rrb;
	int rr;
	int rrr;
	int total;
} s_rcost; */

static s_rcost	ft_calculate_cost(int dest_posn, int b_posn, int a_cnt, int b_cnt)
{
	s_rcost cost;

	cost.ra = 0;
	cost.rra = 0;
	cost.rb = 0;
	cost.rrb = 0;
	cost.rr = 0;
	cost.rrr = 0;
	cost.total = 0;

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

static void ft_consume_cost(s_stack **a, s_stack **b, s_rcost cost)
{
	while (cost.ra > 0)
	{
		rotate_up(*a);
		cost.ra--;
	}
	while (cost.rb > 0)
	{
		rotate_up(*b);
		cost.rb--;
	}
	while (cost.rra > 0)
	{
		rotate_down(*a);
		cost.rra--;
	}
	while (cost.rrb > 0)
	{
		rotate_down(*b);
		cost.rrb--;
	}
	while (cost.rr > 0)
	{
		rotate_up(*a);
		rotate_up(*b);
		cost.rr--;
	}
	while (cost.rrr > 0)
	{
		rotate_down(*a);
		rotate_down(*b);
		cost.rrr--;
	}
}

//Greedy fit
void	algo_2(s_stack *a, s_stack *b, s_arr *lis, int *grand_total)
{
	int	i;
	int	dest_posn;
	int	cost_cap;
	s_rcost cost;

	cost_cap = 10;
	while (b -> cnt > 0)
	{
		i = 0;
		dest_posn = 0;
		cost_cap += 10;
		while (i < b -> cnt)
		{
			dest_posn = ft_mod_binary_search(a, b -> array[i].index);
			cost = ft_calculate_cost(dest_posn, i, a -> cnt, b -> cnt);
			//printf("Cost to place number %-3i: %-3i\n",b -> array[i].index, cost.total);
			if (cost.total < cost_cap)
			{
				//printf("Consume\n");
				*grand_total += cost.total;
				ft_consume_cost(&a, &b, cost);
				lis -> array[b -> array[0].index] = 1;
				(*grand_total)++;
				push(b,a);
			}
			i++;
		}
	}
}
