/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:55:03 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/06 16:41:50 by noobdevbot2      ###   ########.fr       */
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

static void	find_best_move(s_stack *a, s_stack *b, s_rcost *best_cost, int *best_idx)
{
	int	i;
	int	dest_posn;
	s_rcost	cost;

	i = 0;
	best_cost->total = INT_MAX;
	*best_idx = 0;

	while (i < b->cnt)
	{
		dest_posn = ft_mod_binary_search(a, b->array[i].index);
		cost = ft_calculate_cost(dest_posn, i, a->cnt, b->cnt);
		if (cost.total < best_cost->total)
		{
			*best_cost = cost;
			*best_idx = i;
		}
		i++;
	}
}

void	algo_2(s_stack *a, s_stack *b, s_arr *lis, int *grand_total)
{
	int		best_idx;
	s_rcost	best_cost;

	while (b->cnt > 0)
	{
		find_best_move(a, b, &best_cost, &best_idx);
		*grand_total += best_cost.total;
		ft_consume_cost(a, b, &best_cost);
		printf("pa\n");
		push(b, a);
		(*grand_total)++;
	}
}
