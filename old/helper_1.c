/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh@student.42singapore.sg <jsoh@stude    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:40:34 by jsoh@studen       #+#    #+#             */
/*   Updated: 2025/08/29 19:40:34 by jsoh@studen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_view_pair(s_pair a)
{
	printf("Up:%5i Down:%5i\n",a.up,a.down);
}

void ft_view_final_cost(s_rcost cost)
{
	printf("---Final Cost---\n");
	printf("ra :%-4i rb :%-4i rr :%-4i\n", cost.ra, cost.rb, cost.rr);
	printf("rra:%-4i rrb:%-4i rrr:%-4i\n", cost.rra, cost.rrb, cost.rrr);
}
