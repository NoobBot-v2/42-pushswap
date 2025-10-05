/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1_rebuild.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:09:57 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/05 15:57:19 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

static int dist_last_lis(s_arr *lis, s_stack *s)
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

static int dist_to_next_lis(s_arr *lis, s_stack *s)
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

static int	ft_search_b_posn(s_stack *a, s_stack *b, s_arr *lis)
{
	int	prev_lis;
	int	next_lis;
	int	i;
	int	current;

	i = 0;
	current = -1;
	prev_lis = a -> array[dist_last_lis(lis, a)].index;
	next_lis = a -> array[dist_to_next_lis(lis, a)].index;
	printf("last_lis: %3i\n",prev_lis);
	printf("next_lis: %3i\n",next_lis);
	while (i < b -> cnt)
	{
		current = b -> array[i].index;
		if (prev_lis < current && current < next_lis)
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_b_rotation(s_stack **b, int b_posn, int *grand_total)
{
	int	i;
	int	b_cnt;

	i = 0;
	if ((*b) -> cnt == 0)
		return ;
	b_cnt = (*b) -> cnt;
	if (b_cnt - b_posn < b_posn)
	{
		i = b_cnt - b_posn;
		while (i > 0)
		{
			printf("rrb\n");
			rotate_down(*b);
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
			rotate_up(*b);
			(*grand_total)++;
			i--;
		}
	}
}

static void	ft_check_b(s_stack *a, s_stack *b, s_arr *lis, int *grand_total)
{
	int	prev_lis;
	int	next_lis;
	int	b_posn;
	int	i;

	i = 0;
	if (a -> cnt == 0 || b -> cnt == 0)
		return ;
	b_posn = ft_search_b_posn(a, b, lis);
	if (0 <= b_posn && b_posn < 10)
	{
		ft_b_rotation(&b, b_posn, grand_total);
		printf("Pushing fit: %-3i\n", b -> array[0].index);
		lis -> array[b -> array[0].index] = 1;
		(*grand_total)++;
		push(b,a);
		(*grand_total)++;
		rotate_up(a);
	}
}
static void ft_partial_check(s_stack *a, s_stack *b, int num, int *grand_total)
{
	/* int chunk_size = 10; // ranges like 0-9, 10-19, etc.
	int max_rotations = 3; // max number of allowed rotations to reach chunk
	int rotations = 0;

	if (b->cnt == 0)
	{
		(*grand_total)++;
		push(a, b);
		return;
	}

	// Rotate B at most max_rotations to try to reach a matching chunk
	while ((b->array[0].index / chunk_size) != (num / chunk_size) && rotations < max_rotations)
	{
		(*grand_total)++;
		rotate_up(b);
		rotations++;
	}
 */
	// Push num into B, either in-chunk (if we rotated) or on top (if rotation limit reached)
	(*grand_total)++;
	push(a, b);
}



static void	ft_check_push(s_stack **a, s_stack **b, s_arr *lis, int *grand_total)
{
	int	current;
	int	b_fit;

	current = (*a) -> array[0].index;
	if (lis -> array [current] == 0)
	{
		printf("pushing: %-3i\n", current);
		ft_partial_check(*a, *b, current, grand_total);
	}
	else
	{
		printf("rotate\n");
		(*grand_total)++;
		rotate_up(*a);
	}
}

static void	ft_check_swap(s_stack **a, s_arr *lis, int *grand_total)
{
	int	current;
	int	next;

	if ((*a) -> cnt < 2)
		return ;
	current = (*a) -> array[0].index;
	next = (*a) -> array[1].index;
	if (lis -> array[current] || lis -> array[next])
	{
		if (current - next == 1)
		{
			printf("swap\n");
			(*grand_total)++;
			swap(*a);
			lis -> array[next] = 1;
			lis -> array[current] = 1;
		}
	}
}

void	algo_1(s_stack *a, s_stack *b, s_arr *lis, int *grand_total)
{
	int	i;

	i = 0;
	if (!a || !b)
		return ;
	while (i < a -> cap)
	{
		printf("\n----------\nCurrent Number: %-3i\n", a -> array[0].index);
		ft_check_swap(&a, lis, grand_total);
		ft_check_push(&a, &b, lis, grand_total);
		printf("Current Number: %-3i\n", a -> array[0].index);
		ft_check_b(a, b, lis, grand_total);
		i++;
	}
	printf("Algo 1 moves: %-3i\n",*grand_total);
}
