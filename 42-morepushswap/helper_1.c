/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 11:21:05 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/05 13:35:37 by jsoh             ###   ########.fr       */
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
	if (!(*arr) || !(arr))
		return ;
	free((*arr) -> array);
	free(*arr);
	(*arr) = NULL;
}
