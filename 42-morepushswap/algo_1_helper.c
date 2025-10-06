/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:51:10 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/06 14:58:57 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

int dist_last_lis(s_arr *lis, s_stack *s)
{
	int i;

	i = s -> cnt;
	while (i > 0)
	{
		if (lis -> array[s -> array[i].index] == 1)
			return (i);
		i--;
	}
	return (-1);
}

int dist_to_next_lis(s_arr *lis, s_stack *s)
{
	int i;

	i = 0;
	while (i < s -> cnt)
	{
		if (lis -> array[s -> array[i].index] == 1)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_search_b_posn(s_stack *a, s_stack *b, s_arr *lis)
{
	int	prev_lis;
	int	next_lis;
	int	i;
	int	current;

	i = 0;
	current = -1;
	prev_lis = a -> array[dist_last_lis(lis, a)].index;
	next_lis = a -> array[dist_to_next_lis(lis, a)].index;
	while (i < b -> cnt)
	{
		current = b -> array[i].index;
		if (prev_lis < current && current < next_lis)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_b_rotation(s_stack *b, int b_posn, int *grand_total)
{
	int	i;
	int	b_cnt;

	i = 0;
	if (b -> cnt == 0)
		return ;
	b_cnt = b -> cnt;
	if (b_cnt - b_posn < b_posn)
	{
		i = b_cnt - b_posn;
		while (i > 0)
		{
			printf("rrb\n");
			rotate_down(b);
			(*grand_total)++;
			i--;
		}
	}
	else
	{
		i = b_posn;
		while (i > 0)
		{
			printf("rb\n");
			rotate_up(b);
			(*grand_total)++;
			i--;
		}
	}
}
