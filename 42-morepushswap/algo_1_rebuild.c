/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1_rebuild.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:09:57 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/04 17:16:53 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

static void	ft_check_swap(s_stack **a, s_arr *lis)
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
			swap(*a);
			lis -> array[next] = 1;
			lis -> array[current] = 1;
		}
	}
}

static void	ft_check_push(s_stack **a, s_stack **b, s_arr *lis)
{
	int	current;

	current = (*a) -> array[0].index;
	if (lis -> array [current] == 0)
	{
		printf("pushing: %-3i\n", current);
		push(*a, *b);
	}
	else
	{
		printf("rotate\n");
		rotate_up(*a);
	}
}

static void	ft_get_next_lis(int *lis_1, int *lis_2, s_arr *lis, s_stack *a)
{
	int	i;
	int	current;

	i = 0;
	*lis_1 = -1;
	*lis_2 = -1;
	while (i < a -> cnt)
	{
		current = a -> array[i].index;
		if (lis -> array[current])
		{
			if (*lis_1 == -1)
				*lis_1 = current;
			else if (*lis_2 == -1)
				*lis_2 = current;
		}
		i++;
	}
	printf("lis_1: %-3i, lis_2: %-3i\n", *lis_1, *lis_2);
}

static int	ft_search_b(int lis_1, int lis_2, s_stack *b)
{
	int	i;
	int	current;

	i = 0;
	while (i < b -> cnt)
	{
		current = b -> array[i].index;
		if (lis_1 < current && current < lis_2)
		{
			printf("Closest found b to fit: %-3i\n", current);
			return (current);
		}
		i++;
	}
	return (-1);
}

void	algo_1(s_stack *a, s_stack *b, s_arr *lis)
{
	int	i;
	int	lis_1;
	int	lis_2;
	int	current;

	i = 0;
	if (!a || !b)
		return ;
	while (i < a -> cap)
	{
		ft_check_swap(&a, lis);
		ft_check_push(&a, &b, lis);
		i++;
	}
}
