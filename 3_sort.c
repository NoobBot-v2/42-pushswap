/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:13:11 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 16:33:52 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_3_sort(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->array[0].val;
	mid = a->array[1].val;
	bot = a->array[2].val;
	if ((top > mid && mid < bot && top < bot)
		|| (top > mid && mid > bot)
		|| (top < mid && mid > bot && top < bot))
	{
		swap(a);
		ft_printf("sa\n");
	}
}
