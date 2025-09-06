/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_LIS_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:32:28 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/05 21:27:38 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// typedef struct s_num
// {
// 	int val;
// 	int order;
// } s_num;

//problem with the chunking
int LIS_search(s_stack *s, int offset)
{
	int i;
	int length;
	int last_max;

	length = 1;
	i = 0 + offset;
	last_max = s -> array[i];
	while (i < s -> cnt)
	{
		if (last_max < s -> array[i])
		{
			//printf("%-3i\n",last_max);
			last_max = s -> array[i];
			length++;
		}
		i++;
	}
	//printf("%-3i\n",last_max);//There is always one last max not displayed
	return (length);
}

int LIS_loop(s_stack *s)
{
	int i;
	int LIS_index;
	int LIS_len;

	LIS_index = 0;
	i = 0;
	LIS_len = LIS_search(s, i);
	while (i < s -> cnt)
	{
		if (LIS_len < LIS_search(s, i))
		{
			LIS_len = LIS_search(s, i);
			LIS_index = i;
		}
		if (LIS_len > (s -> cnt - 1))
			break ;
		i++;
	}
	//printf("longest_len: %-3i\n",LIS_len);
	//printf("longest_start_idx: %-3i\n",LIS_index);
	return (LIS_index);
}

void LIS_assign(s_stack *s, int start)
{
	int i;
	int length;
	int last_max;
	int order;

	order = 1;
	length = 1;
	i = start;
	last_max = s -> array[i];
	while (i < s -> cnt)
	{
		s -> test_array[i] = (s_num){0};
		if (last_max < s -> array[i])
		{
			last_max = s -> array[i];
			s -> test_array[i].val = s -> array[i];
			s -> test_array[i].order = order;
			order++;
			length++;
		}
		else
		{
			s -> test_array[i].val = s -> array[i];
		}
		i++;
	}
	i = 0;
	while (i < start)
	{
		s -> test_array[i] = (s_num){0};
		if (last_max < s -> array[i])
		{
			last_max = s -> array[i];
			s -> test_array[i].val = s -> array[i];
			s -> test_array[i].order = order;
			order++;
			length++;
		}
		else
			s -> test_array[i].val = s -> array[i];
		i++;
	}
}

void LIS_bounds(s_stack *s)
{
	int i;

	i = 0;
	while (i < s -> cnt - 1)
	{
		if (s -> test_array[i].order > 0 && s -> test_array[i + 1].order == 0)
			if (s -> test_array[i].val > s -> test_array[i + 1].val)
			{
				printf("swapping:%-3i, %-3i\n",s -> test_array[i].val,s -> test_array[i + 1].val);
				swap(s);
				//LIS_assign(s, LIS_loop(s));
			}
		ra(s);
		i++;
	}
	LIS_assign(s, LIS_loop(s));
}
