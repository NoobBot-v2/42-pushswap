/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:20:01 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/07 11:51:51 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rb(t_stack *s, int c, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		ft_printf("r%c\n", c);
		rotate_up(s);
		i++;
	}
}

void	ft_rra_rrb(t_stack *s, int c, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		ft_printf("rr%c\n", c);
		rotate_down(s);
		i++;
	}
}

void	ft_rr(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		ft_printf("rr\n");
		rotate_up(a);
		rotate_up(b);
		i++;
	}
}

void	ft_rrr(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		ft_printf("rrr\n");
		rotate_down(a);
		rotate_down(b);
		i++;
	}
}
