/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 20:06:10 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/28 21:11:40 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

void find_next_gap(s_stack *s, s_arr *lis)
{
	int i;
	int head;
	int front_dist;
	int back_dist;

	head = s -> array[0].index;
	//head = lis -> array[head];
	front_dist = lis -> n - head;
	back_dist = head;
	i = 0;
	while (i < front_dist)
	{
		if (lis -> array[head + i] == 0)
			break;
		i++;
	}
	while (back_dist > 0)
	{
		if (lis -> array[back_dist] == 0)
			break;
		back_dist--;
	}
	if (i < head - back_dist)
		printf("Foward closest gap in LIS: %3i\n", i);
	else
		printf("Backward closest gap in LIS: %3i\n", head - back_dist);
}

int binary_insert_posn(s_stack *s, int num, int offset)
{
	int low = 0;
	int high = s->cnt - 1;
	int mid;
	int mid_val;

	if (s->cnt == 0)
		return 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		mid_val = s->array[(offset + mid) % s->cnt].index;

		if (num < mid_val)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (offset + low) % s->cnt;
}

void algo_controller_2(s_stack *a, s_stack *b, s_arr *lis)
{
	int min_idx;
	int dest_posn;
	int i;

	i = 0;
	min_idx = get_min_index(a);
	while (i < b -> cnt)
	{
		dest_posn = binary_insert_posn(a, b -> array[i].index, min_idx);
		//printf("dest_posn: %3i num: %3i\n",dest_posn, b -> array[i].index);
		i++;
	}
}
