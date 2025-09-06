/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:56:20 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/06 17:41:07 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_max_index(const s_stack *stack)
{
	int	index;
	int	max_num;
	int	max_index;

	index = 0;
	max_index = 0;
	max_num = stack -> array[max_index];
	while (index < stack -> cnt)
	{
		if (stack -> array[index] >= max_num)
		{
			max_num = stack -> array[index];
			max_index = index;
		}
		index++;
	}
	return (max_index);
}

int	get_min_index(const s_stack *stack)
{
	int	index;
	int	min;
	int	min_index;

	index = 0;
	min_index = 0;
	min = stack -> array[min_index];
	while (index < stack -> cnt)
	{
		if (stack -> array[index] <= min)
		{
			min = stack -> array[index];
			min_index = index;
		}
		index++;
	}
	return (min_index);
}

int	get_max_num(const s_stack *stack)
{
	return(stack -> array[get_max_index(stack)]);
}

int	get_min_num(const s_stack *stack)
{
	return(stack -> array[get_min_index(stack)]);
}
