/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:56:20 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/06 17:41:05 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

int	get_max_index(const s_stack *s)
{
	int	index;
	int	max_num;
	int	max_index;

	index = 0;
	max_index = 0;
	max_num = s -> array[max_index].val;
	while (index < s -> cnt)
	{
		if (s -> array[index].val >= max_num)
		{
			max_num = s -> array[index].val;
			max_index = index;
		}
		index++;
	}
	return (max_index);
}

int	get_min_index(const s_stack *s)
{
	int	index;
	int	min;
	int	min_index;

	index = 0;
	min_index = 0;
	min = s -> array[min_index].val;
	while (index < s -> cnt)
	{
		if (s -> array[index].val <= min)
		{
			min = s -> array[index].val;
			min_index = index;
		}
		index++;
	}
	return (min_index);
}

int	get_max_num(const s_stack *s)
{
	return(s -> array[get_max_index(s)].val);
}

int	get_min_num(const s_stack *s)
{
	return(s -> array[get_min_index(s)].val);
}
