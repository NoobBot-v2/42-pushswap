/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 08:58:23 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/03 16:11:22 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

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

static int	ft_find_head_idx(s_stack *s, s_arr *lis)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < s -> cap)
	{
		if (lis -> array[i] == 1)
			break ;
		i++;
	}
	while (j < s -> cap)
	{
		if (s -> array[j].index == i)
			break;
		j++;
	}
	return (j);
}

static int	ft_find_end_value(int cap, s_arr *lis)
{
	int i;

	i = cap;
	while (0 < i)
	{
		if (lis -> array[i] == 1)
			break ;
		i--;
	}
	return (i);
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
	//for (int k = 0; k < s -> cap ; k++)
	//	printf("%i\n",lis -> array[k]);
	printf("Tail Len: %i\n",tails -> n);
	printf("Head idx: %i\n",ft_find_head_idx(s, lis));
	printf("End value: %i\n",ft_find_end_value(s -> cap, lis));
	ft_free_arr(prev);
	ft_free_arr(tails);
}
