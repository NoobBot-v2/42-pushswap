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

int	get_max(s_stack *stack)
{
	int	index;
	int	max_num;

	index = 0;
	max_num = stack -> array[(stack -> start + index) % stack -> cap];
	while (index < stack -> cnt)
	{
		if (stack -> array[(stack -> start + index) % stack -> cap] >= max_num)
			max_num = stack -> array[(stack -> start + index) % stack -> cap];
		index++;
	}
	return (max_num);
}

int	get_min(s_stack *stack)
{
	int	index;
	int	min;

	index = 0;
	min = stack -> array[(stack -> start + index) % stack -> cap];
	while (index < stack -> cnt)
	{
		if (stack -> array[(stack -> start + index) % stack -> cap] <= min)
			min = stack -> array[(stack -> start + index) % stack -> cap];
		index++;
	}
	return (min);
}
