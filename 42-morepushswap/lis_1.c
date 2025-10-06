/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 08:58:23 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/06 15:54:21 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

static int	home_min(s_stack *s)
{
	int	i;

	i = 0;
	while (s -> array[0].index != 0)
	{
		rotate_up(s);
		i++;
	}
	return (i--);
}

static void	original_idx(s_stack *s, int offset)
{
	while (offset > 0)
	{
		rotate_down(s);
		offset--;
	}
}

//Finds the first longest lis
void	lis_controller(s_stack *s, s_arr *lis)
{
	s_arr	*tails;
	s_arr	*prev;
	int		i;
	int		offset;

	i = 0;
	ft_init_arr(&tails, s -> cap);
	ft_init_arr(&prev, s -> cap);
	offset = home_min(s);
	tails -> n = 0;
	prev -> n = s -> cap;
	while (i < prev -> n)
		prev -> array[i++] = -1;
	ft_tails(s, tails, prev);
	ft_construct_lis(s, tails, prev, lis);
	original_idx(s, offset);
	ft_free_arr(&prev);
	ft_free_arr(&tails);
}
