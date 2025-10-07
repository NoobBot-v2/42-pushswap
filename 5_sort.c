/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:13:31 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 17:04:55 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}

static void	ft_pa(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}

//5 elements
void	ft_5_sort(t_stack *a, t_stack *b)
{
	rotate_to_top(a, get_min_index(a));
	ft_pb(a, b);
	rotate_to_top(a, get_min_index(a));
	ft_pb(a, b);
	ft_3_sort(a);
	rotate_to_top(a, get_min_index(a));
	while (b -> cnt > 0)
		ft_pa(a, b);
}
