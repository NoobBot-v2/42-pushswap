/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 11:17:56 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/04 12:14:03 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

int	ft_binary_search(int *tails, int value, int n, s_stack *s)
{
	int	start;
	int	end;
	int	mid;

	start = 0;
	end = n - 1;
	while (start <= end)
	{
		mid = (end + start) / 2;
		if (value >= s -> array[tails[mid]].index)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (start);
}

void	ft_construct_lis(s_stack *s, s_arr *tails, s_arr *prev, s_arr *LIS)
{
	int	prev_num;

	prev_num = tails -> array[tails -> n - 1];
	LIS -> array[s -> array[prev_num].index] = 1;
	LIS -> n = tails -> n;
	prev_num = prev -> array[prev_num];
	while (prev_num != -1)
	{
		LIS -> array[s -> array[prev_num].index] = 1;
		prev_num = prev -> array[prev_num];
	}
}

void	ft_tails(s_stack *s, s_arr *tails, s_arr *prev)
{
	int	i;
	int	posn;

	posn = -1;
	i = 0;
	while (i < s -> cnt)
	{
		posn = ft_binary_search(tails -> array,
				s -> array[i].index, tails -> n, s);
		tails -> array[posn] = i;
		if (posn > 0)
			prev -> array[i] = tails -> array[posn - 1];
		if (posn == tails -> n)
			tails -> n++;
		i++;
	}
}

int	ft_lis_head_idx(s_stack *s, s_arr *lis)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s -> cap)
	{
		if (lis -> array[i] == 1)
			break ;
		i++;
	}
	while (j < s -> cap)
	{
		if (s -> array[j].index == i)
			break ;
		j++;
	}
	return (j);
}

int	ft_lis_end_idx(s_stack *s, s_arr *lis)
{
	int	i;
	int	j;

	i = s -> cap;
	j = s -> cap;
	while (0 < i)
	{
		if (lis -> array[i] == 1)
			break ;
		i--;
	}
	while (0 < j)
	{
		if (s -> array[j].index == i)
			break ;
		j--;
	}
	return (j);
}
