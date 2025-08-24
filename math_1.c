/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:56:20 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/24 18:24:46 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_max(s_stack *s_stk)
{
	int	index;
	int	max_num;

	index = 0;
	max_num = s_stk -> array[(s_stk -> start + index) % s_stk -> cap].num;
	while (index < s_stk -> cnt)
	{
		if (s_stk -> array[(s_stk -> start + index) % s_stk -> cap].num >= max_num)
			max_num = s_stk -> array[(s_stk -> start + index) % s_stk -> cap].num;
		index++;
	}
	return (max_num);
}

int	get_min(s_stack *s_stk)
{
	int	index;
	int	min;

	index = 0;
	min = s_stk -> array[(s_stk -> start + index) % s_stk -> cap].num;
	while (index < s_stk -> cnt)
	{
		if (s_stk -> array[(s_stk -> start + index) % s_stk -> cap].num <= min)
			min = s_stk -> array[(s_stk -> start + index) % s_stk -> cap].num;
		index++;
	}
	return (min);
}

double	normalize(int min, int max, int num, int cap)
{
	double	norm_num;

	if (min == max)
		return (0.0);
	norm_num = 0;
	cap = cap / 1;
	norm_num = (double)(num - min) / (max - min) * (cap - 1);
	return (norm_num);
}
