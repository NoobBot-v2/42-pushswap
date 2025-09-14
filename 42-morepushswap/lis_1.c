/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:02:44 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/14 16:45:41 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

void	create_array(int **arr, int size)
{
	*arr = (int *)malloc(size * sizeof(int));
	if (!*arr)
		*arr = NULL;
}

static int lis(s_stack *s, int offset)
{
	int	i;
	int	len;
	int	lis_len;
	int	last_num;

	lis_len = 1;
	i = 0 + offset;
	last_num = s -> array[i].index;
	printf("------\n");
	while (i < s -> cnt - 1 && lis_len < (s -> cnt) / 2)
	{
		if (last_num < s -> array[i].index)
		{
			printf("%i\n",last_num);
			last_num = s -> array[i].index;
			lis_len++;
		}
		i++;
	}
	printf("%i\n",last_num);
	printf("------\n");
}

static void init_lis(s_stack *s, int **lis_arr, int offset)
{
	int	i;
	int	j;
	int	last_num;

	j = 0;
	i = 0 + offset;
	last_num = s -> array[i].index;
	while (i < s -> cnt - 1)
	{
		if (last_num < s -> array[i].index)
		{
			(*lis_arr)[j] = s -> array[i].index;
			j++;
			last_num = s -> array[i].index;
		}
		i++;
	}
}
// Create a lis array to store the sequence, loop through the stack to create this sequence
// Malloc only once
void	lis_controller(s_stack *s, int **lis_arr)
{
	int	i;
	int	longest_len;
	int	lis_len;
	int	lis_start;

	i = 0;
	lis_len = lis(s ,i);
	longest_len = lis_len;
	lis_start = 0;
	while (i < s -> cnt - 1 && longest_len < ((s -> cnt - 1)/2))
	{
		lis_len = lis(s ,i);
		if (longest_len < lis_len)
		{
			longest_len = lis_len;
			lis_start = i;
		}
		i++;
	}
	//This lis_start is wrong
	init_lis(s, lis_arr, lis_start);
	//debug
	i = 0;
	printf("Longest len:%i\n",longest_len);
	while (i < longest_len)
	{
		printf("lis:%i\n",(*lis_arr)[i]);
		i++;
	}
}



