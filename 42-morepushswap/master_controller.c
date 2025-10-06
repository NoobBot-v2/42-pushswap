/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:41:10 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/06 16:18:29 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

void	ft_init(s_stack **a, s_arr **lis, int argc, char const *argv[])
{
	stack_create(a, argc, 'a');
	stack_init(*a, argv);
	radix_controller(*a);
	ft_init_arr(lis, (*a) -> cap);
	lis_controller(*a,*lis);
}

void	ft_free_all(s_stack **a, s_stack **b, s_arr **lis)
{
	if (lis && *lis)
	{
		ft_free_arr(lis);
		*lis = NULL;
	}
	if (a && *a)
	{
		stack_free(a);
		*a = NULL;
	}
	if (b && *b)
	{
		stack_free(b);
		*b = NULL;
	}
}
