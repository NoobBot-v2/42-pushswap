/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:20:01 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/06 15:51:42 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

void	ft_ra_rb(s_stack *s, int c, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		printf("r%c\n",c);
		rotate_up(s);
		i++;
	}
}

void	ft_rra_rrb(s_stack *s, int c, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		printf("rr%c\n",c);
		rotate_down(s);
		i++;
	}
}

void	ft_rr(s_stack *a, s_stack *b, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		printf("rr\n");
		rotate_up(a);
		rotate_up(b);
		i++;
	}
}

void	ft_rrr(s_stack *a, s_stack *b, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		printf("rrr\n");
		rotate_down(a);
		rotate_down(b);
		i++;
	}
}
