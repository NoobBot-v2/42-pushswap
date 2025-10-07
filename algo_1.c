/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:09:57 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:49:27 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_push(t_stack *a, t_stack *b, t_arr *lis)
{
	int	current;

	current = a -> array[0].index;
	if (lis -> array [current] == 0)
	{
		ft_printf("pb\n");
		push(a, b);
	}
	else
		ft_ra_rb(a, 'a', 1);
}

static void	ft_check_swap(t_stack *a, t_arr *lis)
{
	int	current;
	int	next;

	if (a -> cnt < 2)
		return ;
	current = a -> array[0].index;
	next = a -> array[1].index;
	if (lis -> array[current] || lis -> array[next])
	{
		if (current - next == 1)
		{
			ft_printf("sa\n");
			swap(a);
			lis -> array[next] = 1;
			lis -> array[current] = 1;
		}
	}
}

void	algo_1(t_stack *a, t_stack *b, t_arr *lis)
{
	int	i;

	i = 0;
	if (!a || !b)
		return ;
	while (i < a -> cap)
	{
		ft_check_swap(a, lis);
		ft_check_push(a, b, lis);
		i++;
	}
}
