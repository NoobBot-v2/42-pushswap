/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:19:54 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/09/25 15:59:38 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

//Takes in the s_stack and lis
void	algo_controller(s_stack *a, s_stack *b, s_arr *lis)
{
	int	i;

	i = 0;
	while (i < a -> cnt)
	{
		//If number is not in LIS
		if (lis -> array[a -> array[0].index] == 0)
		{
			push(a, b);
		}
		else
		{
			rotate_up(a);
			i++;
		}
	}
}
