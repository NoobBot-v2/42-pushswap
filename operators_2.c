/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:12:29 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/24 17:00:18 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//void	push(s_stack *stk_a, s_stack *stk_b)
void	dbl_swap(s_stack *stk_a, s_stack *stk_b)
{
	swap(stk_a);
	swap(stk_b);
}

void	dbl_rotate_up(s_stack *stk_a, s_stack *stk_b)
{
	rotate_up(stk_a);
	rotate_up(stk_b);
}

void	dbl_rotate_down(s_stack *stk_a, s_stack *stk_b)
{
	rotate_down(stk_a);
	rotate_down(stk_b);
}