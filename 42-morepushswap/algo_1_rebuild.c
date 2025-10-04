/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1_rebuild.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:09:57 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/05 00:37:35 by jsoh             ###   ########.fr       */
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

static void	ft_check_b(s_stack *a, s_stack *b, s_arr *lis)
{
	int	prev_lis;
	int	next_lis;
	int	current;
	int	i;

	i = 0;
	prev_lis = a -> array[dist_last_lis(lis, a)].index;
	next_lis = a -> array[dist_to_next_lis(lis, a)].index;
	printf("last_lis: %3i\n",prev_lis);
	printf("next_lis: %3i\n",next_lis);
	while (i < b -> cnt)
	{
		current = b -> array[i].index;
		//means we check for a new tail or new head
		if (prev_lis > next_lis)
		{
			//new tail or new head
			if (prev_lis < current || current < next_lis)
			{
				while (i > 0)
				{
					printf("rb\n");
					rotate_up(b);
					i--;
				}
				printf("push new tail/head\n");
				lis -> array[current] = 1;
				push(b,a);
				rotate_up(a);
				break;
			}
		}//check if it fits
		else if (prev_lis < current && current < next_lis)
		{
			while (i > 0)
			{
				printf("rb\n");
				rotate_up(b);
				i--;
			}
			printf("push a number that fits: %-3i\n", current);
			lis -> array[current] = 1;
			//stack_view(a);
			//stack_view(b);
			push(b,a);
			rotate_up(a);
			break;
		}
		i++;
	}
}

static void	ft_check_push(s_stack **a, s_stack **b, s_arr *lis)
{
	int	current;
	int	b_fit;

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

void	algo_1(s_stack *a, s_stack *b, s_arr *lis)
{
	int	i;

	i = 0;
	if (!a || !b)
		return ;
	while (i < a -> cap)
	{
		printf("\n----------\nCurrent Number: %-3i\n", a -> array[0].index);
		ft_check_swap(&a, lis);
		ft_check_push(&a, &b, lis);
		printf("Current Number: %-3i\n", a -> array[0].index);
		ft_check_b(a, b, lis);
		i++;
	}
}
