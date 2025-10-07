/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:41:10 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/07 11:51:13 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_stack **a, t_arr **lis, int argc, char const *argv[])
{
	stack_create(a, argc, 'a');
	stack_init(*a, argv);
	radix_controller(*a);
	ft_init_arr(lis, (*a)-> cap);
	lis_controller(*a,*lis);
}

void	ft_free_all(t_stack **a, t_stack **b, t_arr **lis)
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
