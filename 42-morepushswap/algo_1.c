/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:19:54 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/09/27 18:42:53 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

//Returns distance to the first number in b that fits the LIS
static int check_b_stack(s_stack *s, int lis_num, int min_num, int dist)
{
	int	i;

	i = 0;
	if (s -> cnt == 0)
		return (-1);
	while (i < dist)
	{
		if (min_num < s -> array[i].index && s -> array[i].index < lis_num)
			break ;
		i++;
	}
	//distance to the top
	return (i);
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

static int dist_to_last_lis(s_arr *lis, s_stack *s)
{
	int i;

	i = s -> cnt - 1;
	while (i > 0)
	{
		if (lis -> array[s -> array[i].index] == 1)
			return (i);
		i--;
	}
	return (-1);
}

//Takes in the s_stack and lis
void	algo_controller(s_stack *a, s_stack *b, s_arr *lis)
{
	int	i;
	int	dist_lis;
	int	lis_val;
	int	b_fit;

	i = 0;
	while (i < a -> cnt)
	{
		//Always print next LIS Flag outside
		dist_lis = dist_to_next_lis(lis, a);
		lis_val = a -> array[dist_lis].index;
		printf("dist: %3i val: %3i\n", dist_lis, lis_val);
		/* if (b -> cnt > 0)
		{
			printf("%3i\n",a -> array[dist_to_last_lis(lis, a)].index);
			b_fit = check_b_stack(b, lis_val, a -> array[dist_to_last_lis(lis, a)].index, dist_lis);
			if (b_fit != -1)
			{
				lis -> array[b -> array[b_fit].index] = 1;
				while (b_fit > 0)
				{
					rotate_up(b);
					b_fit--;
				}
				push(b, a);
				rotate_up(a);
			}
		}*/
		//If number is not in LIS
		if (lis -> array[a -> array[0].index] == 0)
		{
			push(a, b);
		}
		else
		{
			//prev LIS flag has been reached, find the next LIS flag starting from prev LIS flag
			rotate_up(a);
			i++;
		}
	}
}
