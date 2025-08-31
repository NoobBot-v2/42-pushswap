/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:44:02 by jsoh@studen       #+#    #+#             */
/*   Updated: 2025/08/31 14:42:10 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int cost_median(s_rcost *cost, int size)
{
	int i;
	int sum;

	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += cost[i].total;
		i++;
	}
	return (sum / i);
}

int lowest_cost_index(s_rcost *cost, int size)
{
	int i;
	int min;

	i = 0;
	min = cost[i].total;
	while (i < size)
	{
		if (cost[i].total < min)
			min = cost[i].total;
		i++;
	}
	return (i);
}
