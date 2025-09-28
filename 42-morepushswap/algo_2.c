/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:01:06 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/28 20:04:38 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

static int	find_closest_missing_num(s_stack *a, s_arr *lis)
{
	int current_num;
	int up_num;
	int down_num;
	int i;

	current_num = a -> array[0].index;
	//lis -> array[a -> array[i].index] == 1
	//While +i in either direction of lis is 1 until it hits 0
	i = 1;
	up_num = current_num - i;
	down_num = current_num + i;
	if (up_num < 0)
		up_num = a -> cnt;
	if (down_num > a -> cnt)
		down_num = 0;
	while (lis -> array[up_num] != 0 && lis -> array[down_num] != 0)
	{
		up_num = current_num - i;
		down_num = current_num + i;
		if (up_num < 0)
			up_num = a -> cnt;
		if (down_num > a -> cnt)
			down_num = 0;
		i++;
		if (i > a -> cnt)
			return (-1);
	}
	if (lis -> array[up_num] == 0)
		return (up_num);
	else
		return (down_num);
}

static void surface_a(s_stack *s, int num)
{
	int current_num;
	int dist;

	current_num = s -> array[0].index;
	if (num > current_num)
	{
		dist = num - current_num;
		while (dist > 0)
		{
			//printf("ra\n");
			rotate_up(s);
			dist--;
		}
	}

}

static void surface_b(s_stack *b, int r_start, int r_end)
{
	int i;

	i = 0;
	if (b -> cnt == 0)
	{
		printf("b_cnt: %3i\n", b -> cnt);
		return ;
	}
	while (i < b -> cnt)
	{
		if (r_start > b -> array[i].index && b -> array[i].index > r_end)
		{
			printf("b_num: %3i\n",b -> array[i].index);
			break;
		}
		i++;
	}
	while (i > 0)
	{
		//printf("rb\n");
		rotate_up(b);
		i--;
	}
}

//Find the next best moves to re-add b into a
//Find the closest missing LIS number from current position in a
//Find the closest fits from B
void	algo_controller_2(s_stack *a, s_stack *b, s_arr *lis)
{
	int dist_closest_miss;
	int b_dist;
	int range_start;
	int range_end;

	dist_closest_miss = find_closest_missing_num(a, lis);
	printf("Closest Missing LIS val: %3i\n",dist_closest_miss);
	surface_a(a, dist_closest_miss);
	range_start = a -> array[a -> cnt - 1].index;
	range_end = a -> array[0].index;
	printf("r_start: %3i r_end: %3i\n",range_start, range_end);
	surface_b(b, range_start, range_end);
	/*while (b -> cnt > 0)
	{
		dist_closest_miss = find_closest_missing_num(a, lis);
		//printf("Closest Missing LIS val: %3i\n",dist_closest_miss);
		surface_a(a, dist_closest_miss);
		//Check what numbers in range can fit
		range_start = a -> array[a -> cnt - 1].index;
		range_end = a -> array[0].index;
		//printf("r_start: %3i r_end: %3i\n",range_start, range_end);
		surface_b(b, range_start, range_end);
		printf("pb\n");
		push(b, a);
		printf("ra\n");
		rotate_up(a);
	} */
}
