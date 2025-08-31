/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh@student.42singapore.sg <jsoh@stude    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:44:02 by jsoh@studen       #+#    #+#             */
/*   Updated: 2025/08/29 21:44:02 by jsoh@studen      ###   ########.fr       */
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
