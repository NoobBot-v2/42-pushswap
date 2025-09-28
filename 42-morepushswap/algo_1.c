/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:19:54 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/09/28 21:15:25 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

//Always starts from the top, so if the last number out of the LIS has been pushed out, it will loop back
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

static int dist_to_next_next_lis(s_arr *lis, s_stack *s)
{
	int i;

	i = 0;
	while (i < s -> cnt)
	{
		if (lis -> array[s -> array[i].index] == 1)
			break ;
		i++;
	}
	i++;//Add 1 more to skip current number
	while (i < s -> cnt)
	{
		if (lis -> array[s -> array[i].index] == 1)
			return (i);
		i++;
	}
	return (-1);
	//Current i of the first encountered lis.
}

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

//Check b returns location of first number that fits
static int check_b_stack(s_stack *s, int last, int next)
{
	int i;

	if (s -> cnt == 0)
		return (-1);
	i = 0;
	//printf("checking\n");
	//If last > next, means its the head/end
	if (last > next)
	{
		while (i < s -> cnt)
		{
			//has to be bigger than both last and first
			if (last < s -> array[i].index && s -> array[i].index > next)
				return (i);
			i++;
		}
	}
	else
	{
		while (i < s -> cnt)
		{
			//0 < 1 && 1 < 2
			if (last < s -> array[i].index && s -> array[i].index < next)
				return (i);
			i++;
		}
	}
	return (-1);
}

//Takes in the s_stack and lis
void	algo_controller_1(s_stack *a, s_stack *b, s_arr *lis)
{
	int	i;
	int	dist_lis;
	int last_lis;
	int	lis_val_1;
	int	lis_val_2;
	int	b_fit;

	int	b_up;
	int	b_down;

	i = 0;
	//Get first lis and keep
	last_lis = dist_last_lis(lis, a);
	lis_val_1 = a -> array[last_lis].index;
	while (i < a -> cnt)
	{
		//Always print next LIS Flag outside
		dist_lis = dist_to_next_lis(lis, a);
		lis_val_2 = a -> array[dist_lis].index;
		//printf("\nfirst dist: %3i val: %3i\n", dist_lis, lis_val_1);
		//printf("2nd   dist: %3i val: %3i\n", dist_lis, lis_val_2);
		b_fit = check_b_stack(b, lis_val_1, lis_val_2);
		if (b_fit > 0)
		{
			//if (lis -> array[a -> array[0].index] == 1)
			//	rotate_up(a);
			lis -> array[b -> array[b_fit].index] = 1;
			b_up = b_fit;
			b_down = b -> cnt - b_fit;
			if (b_down < b_up)
			{
				//printf("rrb: %3i\n",b_up);
				while (b_down)
				{
					//printf("rrb\n");
					rotate_down(b);
					b_down--;
				}
			}
			else
			{
				//printf("rb: %3i\n",b_up);
				while (b_up > 0)
				{
					//printf("rb\n");
					rotate_up(b);
					b_up--;
				}
			}
			//printf("b-fits pushing\n");
			//printf("pb\n");
			push(b, a);
			//printf("ra\n");
			//rotate_up(a);
			last_lis = dist_last_lis(lis, a);
			lis_val_1 = a -> array[last_lis].index;
			dist_lis = dist_to_next_lis(lis, a);
			lis_val_2 = a -> array[dist_lis].index;
		}
		if (lis -> array[a -> array[0].index] == 0)
		{
			//printf("pa\n");
			push(a, b);
		}
		else
		{
			//prev LIS flag has been reached, find the next LIS flag starting from prev LIS flag
			lis_val_1 = a -> array[0].index;
			//printf("ra\n");
			rotate_up(a);
			i++;
		}
	}
}
