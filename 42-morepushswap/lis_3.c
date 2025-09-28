/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 08:58:23 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/09/28 19:59:37 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

//Searches based on value retrieved by indexes stored by tails
//Returns index posn of value in tails
static int ft_binary_search(int *tails_arr, int value, int n, s_stack *s)
{
	int	start;
	int	end;
	int	mid;

	start = 0;
	end = n - 1;
	while (start <= end)
	{
		mid = (end + start) / 2;
		if (value >= s -> array[tails_arr[mid]].index)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (start);
}

//Reconstruct LIS from prev
static void	ft_construct_lis(s_stack *s, s_arr *tails, s_arr *prev, s_arr *LIS)
{
	int	prev_num;

	prev_num = tails -> array[tails -> n - 1];
	LIS -> array[s -> array[prev_num].index] = 1;
	LIS -> n = tails -> n;
	prev_num = prev -> array[prev_num];
	while (prev_num != -1)
	{
		LIS -> array[s -> array[prev_num].index] = 1;
		prev_num = prev -> array[prev_num];
	}
}

//Take s_stack -> array.index
//Refactor tails and prev later on
//*prev is intialized with -1
static void	ft_tails(s_stack *s, s_arr *tails, s_arr *prev)
{
	int	i;
	int	posn;

	posn = -1;
	i = 0;
	while (i < s -> cnt)
	{
		posn = ft_binary_search(tails -> array, s -> array[i].index, tails -> n, s);
		tails -> array[posn] = i;
		if (posn > 0)
			prev -> array[i] = tails -> array[posn - 1];
		if (posn == tails -> n)
			tails -> n++;
		i++;
	}
}

static void	ft_free_arr(s_arr *arr)
{
	if (!arr)
		return ;
	free(arr -> array);
	free(arr);
}

void	lis_controller(s_stack *s, s_arr *lis)
{
	s_arr *tails;
	s_arr *prev;
	int		i;

	i = 0;
	tails = malloc(s -> cap * sizeof(s_arr));
	prev = malloc(s -> cap * sizeof(s_arr));
	if (!tails || !prev)
		return ;
	tails -> array = malloc(s -> cap * sizeof(int));
	prev -> array = malloc(s -> cap * sizeof(int));
	if (!tails -> array || !prev -> array)
		return ;
	tails -> n = 0;
	prev -> n = s -> cap;
	while (i < prev -> n)
		prev -> array[i++] = -1;
	ft_tails(s, tails, prev);
	ft_construct_lis(s, tails, prev, lis);
	printf("Tail Len: %i\n",tails -> n);
	for(int j = 0; j < tails -> n;j++)
	{
		printf("LIS Val:%3i\n",s -> array[tails -> array[j]].index);
	}
	ft_free_arr(prev);
	ft_free_arr(tails);
}
