/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:09:57 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/06 16:44:50 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

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
		ft_b_rotation(b, b_posn, grand_total);
		lis -> array[b -> array[0].index] = 1;
		(*grand_total)++;
		printf("pa\n");
		push(b,a);
		(*grand_total)++;
		printf("ra\n");
		rotate_up(a);
	}
}

static void	ft_check_push(s_stack *a, s_stack *b, s_arr *lis, int *grand_total)
{
	int	current;
	int	b_fit;

	current = a -> array[0].index;
	if (lis -> array [current] == 0)
	{
		printf("pb\n");
		(*grand_total)++;
		push(a, b);
	}
	else
	{
		printf("ra\n");
		(*grand_total)++;
		rotate_up(a);
	}
}

static void	ft_check_swap(s_stack *a, s_arr *lis, int *grand_total)
{
	int	current;
	int	next;

	if (a -> cnt < 2)
		return ;
	current = a -> array[0].index;
	next = a -> array[1].index;
	if (lis -> array[current] || lis -> array[next])
	{
		if (current - next == 1)
		{
			printf("sa\n");
			(*grand_total)++;
			swap(a);
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
		ft_check_swap(a, lis, grand_total);
		ft_check_push(a, b, lis, grand_total);
		i++;
	}
}
