/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 20:06:10 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/28 22:07:48 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

// void find_next_gap(s_stack *s, s_arr *lis)
// {
// 	int i;
// 	int head;
// 	int front_dist;
// 	int back_dist;

// 	head = s -> array[0].index;
// 	//head = lis -> array[head];
// 	front_dist = lis -> n - head;
// 	back_dist = head;
// 	i = 0;
// 	while (i < front_dist)
// 	{
// 		if (lis -> array[head + i] == 0)
// 			break;
// 		i++;
// 	}
// 	while (back_dist > 0)
// 	{
// 		if (lis -> array[back_dist] == 0)
// 			break;
// 		back_dist--;
// 	}
// 	if (i < head - back_dist)
// 		printf("Foward closest gap in LIS: %3i\n", i);
// 	else
// 		printf("Backward closest gap in LIS: %3i\n", head - back_dist);
// }

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

void init_cost(s_rcost *cost)
{
	cost -> ra = 0;
	cost -> rra = 0;
	cost -> rb = 0;
	cost -> rrb = 0;
	cost -> rr = 0;
	cost -> rrr = 0;
	cost -> total = 0;
}

void common_cost(s_rcost *cost)
{
	while(cost -> ra > 0 && cost -> rb > 0)
	{
		cost -> ra--;
		cost -> rb--;
		cost -> rr++;
	}
	while(cost -> rra > 0 && cost -> rrb > 0)
	{
		cost -> rra--;
		cost -> rrb--;
		cost -> rrr++;
	}
}

void total_cost(s_rcost *cost)
{
	int total;

	total = 0;
	total += cost->ra;
	total += cost->rra;
	total += cost->rb;
	total += cost->rrb;
	total += cost->rr;
	total += cost->rrr;
	cost -> total = total;
}

void view_cost(s_rcost *cost)
{
	if (!cost)
	{
		printf("Cost is NULL\n");
		return;
	}
	printf("\nRotation Costs:\n");
	printf("  RA : %3d | RRA : %3d\n", cost->ra, cost->rra);
	printf("  RB : %3d | RRB : %3d\n", cost->rb, cost->rrb);
	printf("  RR : %3d | RRR : %3d\n", cost->rr, cost->rrr);
	printf("  Total Cost : %d\n", cost->total);
}

s_rcost *calculate_cost(int a_cnt, int dest_posn, int b_cnt, int b_posn)
{
	s_rcost *cost;

	if (a_cnt - dest_posn < dest_posn)
		cost -> rra = a_cnt - dest_posn;
	else
		cost -> ra = dest_posn;
	if (b_cnt - b_posn < b_posn)
		cost -> rrb = b_cnt - b_posn;
	else
		cost -> rb = b_posn;
	common_cost(cost);
	total_cost(cost);
	return (cost);
}

void run_cost(s_stack *a, s_stack *b, s_rcost *cost)
{
	while (cost -> ra > 0)
	{
		rotate_up(a);
		cost -> ra--;
	}
	while (cost -> rra > 0)
	{
		rotate_down(a);
		cost -> rra--;
	}
	while (cost -> rb > 0)
	{
		rotate_up(b);
		cost -> rb--;
	}
	while (cost -> rrb > 0)
	{
		rotate_down(b);
		cost -> rrb--;
	}
	while (cost -> rr > 0)
	{
		rotate_up(a);
		rotate_up(b);
		cost -> rr--;
	}
	while (cost -> rrr > 0)
	{
		rotate_down(a);
		rotate_down(b);
		cost -> rrr--;
	}
}

void algo_controller_2(s_stack *a, s_stack *b, s_arr *lis, int *grand_total)
{
	int min_idx;
	int dest_posn;
	int cost_limit;
	int i;
	s_rcost *cost;

	cost = malloc(sizeof(s_rcost));
	if (!cost)
		return ;
	(*grand_total) = 0;
	i = 0;
	cost_limit = 1;
	init_cost(cost);
	min_idx = get_min_index(a);
	while (b -> cnt > 0)
	{
		while (i < b -> cnt)
		{
			dest_posn = binary_insert_posn(a, b -> array[i].index, min_idx);
			//printf("dest_posn: %3i num: %3i\n",dest_posn, b -> array[i].index);
			init_cost(cost);
			cost = calculate_cost(a -> cnt, dest_posn, b -> cnt, i);
			if (cost -> total <= cost_limit)
			{
				//printf("push\n");
				run_cost(a, b, cost);
				push(b, a);
				(*grand_total) += cost->total;
				(*grand_total)++;
				min_idx = get_min_index(a);
			}
			//view_cost(cost);
			i++;
		}
		i = 0;
		cost_limit++;
	}
	free(cost);
}
