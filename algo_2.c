/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:55:03 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:49:45 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	home_min(t_stack *s)
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

static void	original_idx(t_stack *s, int offset)
{
	while (offset > 0)
	{
		rotate_down(s);
		offset--;
	}
}

static int	ft_mod_binary_search(t_stack *s, int value)
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
	original_idx(s, offset);
	return ((start + offset) % s -> cnt);
}

static void	ft_best_move(t_stack *a, t_stack *b, t_rcost *best, int *best_idx)
{
	int		i;
	int		dest_posn;
	t_rcost	cost;

	i = 0;
	best->total = INT_MAX;
	*best_idx = 0;
	while (i < b->cnt)
	{
		dest_posn = ft_mod_binary_search(a, b->array[i].index);
		cost = ft_calculate_cost(dest_posn, i, a->cnt, b->cnt);
		if (cost.total < best->total)
		{
			*best = cost;
			*best_idx = i;
		}
		i++;
	}
}

void	algo_2(t_stack *a, t_stack *b)
{
	int		best_idx;
	t_rcost	best_cost;

	while (b->cnt > 0)
	{
		ft_best_move(a, b, &best_cost, &best_idx);
		ft_consume_cost(a, b, &best_cost);
		ft_printf("pa\n");
		push(b, a);
	}
}
