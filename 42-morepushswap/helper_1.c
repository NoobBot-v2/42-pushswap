/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 11:21:05 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/06 16:34:20 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

void	ft_init_arr(s_arr **arr, int n)
{
	(*arr) = malloc(sizeof(s_arr));
	if (!(*arr))
		return ;
	(*arr) -> array = malloc(n * sizeof(int));
	if (!(*arr) -> array)
	{
		free(*arr);
		*arr = NULL;
		return ;
	}
	else
		ft_memset((*arr)->array, 0, n * sizeof(int));
}

void	ft_free_arr(s_arr **arr)
{
	if (!(arr) || !(*arr))
		return ;
	free((*arr) -> array);
	free(*arr);
	(*arr) = NULL;
}

void rotate_to_top(s_stack *s, int idx, int *grand_total)
{
	int	i;

	i = 0;
	if (idx < 0 || idx >= s->cnt)
		return;
	if (idx <= s->cnt / 2)
	{
		while (i < idx)
		{
			printf("ra\n");
			rotate_up(s);
			(*grand_total)++;
			i++;
		}
	}
	else
	{
		while (i < s->cnt - idx)
		{
			printf("rra\n");
			rotate_down(s);
			(*grand_total)++;
			i++;
		}
	}
}


