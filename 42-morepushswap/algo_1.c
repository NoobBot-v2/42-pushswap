/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:19:54 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/09/25 16:25:05 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

static int get_next_lis(int start, s_arr *lis)
{
	int	i;

	if (start == 0)
		i = start;
	else
		i = start + 1;
	while (i < lis -> n)
	{
		if (lis -> array[i] == 1)
			break;
		i++;
	}
	return (i);
}

//Takes in the s_stack and lis
void	algo_controller(s_stack *a, s_stack *b, s_arr *lis)
{
	int	i;
	int	next_lis;

	i = 0;
	next_lis = get_next_lis(0, lis);
	printf("Current target LIS: %i\n",next_lis);
	while (i < a -> cnt)
	{
		//If number is not in LIS
		if (lis -> array[a -> array[0].index] == 0)
		{
			//printf("push\n");
			push(a, b);
		}
		else
		{
			next_lis = get_next_lis(next_lis, lis);
			//printf("Current target LIS: %i\n",next_lis);
			rotate_up(a);
			i++;
		}
	}
}
