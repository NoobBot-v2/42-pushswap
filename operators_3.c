/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:11:49 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/31 15:43:14 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Include s_costlog later
void ra(s_stack *a)
{
	rotate_up(a);
	printf("ra\n");
}

void rb(s_stack *b)
{
	rotate_up(b);
	printf("rb\n");
}

void rr(s_stack *a, s_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	printf("rr\n");
}

void rra(s_stack *a)
{
	rotate_down(a);
	printf("rra\n");
}

void rrb(s_stack *b)
{
	rotate_down(b);
	printf("rrb\n");
}

void rrr(s_stack *a, s_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	printf("rrr\n");
}

void pa(s_stack *a, s_stack *b)
{
	push(a, b);
	printf("pa\n");
}

void pb(s_stack *a, s_stack *b)
{
	push(b, a);
	printf("pb\n");
}