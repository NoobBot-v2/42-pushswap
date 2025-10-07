/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 11:21:05 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:50:18 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_arr(t_arr **arr, int n)
{
	(*arr) = malloc(sizeof(t_arr));
	if (!(*arr))
		return ;
	(*arr)-> array = malloc (n * sizeof(int));
	if (!(*arr)-> array)
	{
		free(*arr);
		*arr = NULL;
		return ;
	}
	else
		ft_memset((*arr)-> array, 0, n * sizeof(int));
}

void	ft_free_arr(t_arr **arr)
{
	if (!(arr) || !(*arr))
		return ;
	free((*arr)-> array);
	free(*arr);
	(*arr) = NULL;
}

void	rotate_to_top(t_stack *s, int idx)
{
	if (idx < 0 || idx >= s->cnt)
		return ;
	if (idx <= s -> cnt / 2)
		ft_ra_rb(s, 'a', idx);
	else
		ft_rra_rrb(s, 'a', (s -> cnt - idx));
}
