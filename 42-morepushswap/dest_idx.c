/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dest_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:52:59 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/06 20:12:13 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

static void	split_stack(s_stack *s, s_stack *positive, s_stack *negative)
{
	int i;

	i = 0;
	while (i < s -> cnt)
	{
		if (s -> array[i].val >= 0)
		{
			positive -> array[positive -> cnt] = s -> array[i];
			positive -> cnt ++;
		}
		else
		{
			negative -> array[negative -> cnt] = s -> array[i];
			negative -> array[negative -> cnt].val *= -1;
			negative -> cnt ++;
		}
		i++;
	}
}

static void original_dest(s_stack *s)
{
	s_stack	*temp;
	int		i;
	int		orig_idx;

	stack_create(&temp, s -> cap, 'b');
	if (!temp)
		return ;
	temp -> cnt = s -> cnt;
	i = 0;
	while (i < s -> cnt)
	{
		temp -> array[i] = s -> array[i];
		i++;
	}
	i = 0;
	while (i < s -> cnt)
	{
		orig_idx = temp -> array[i].index;
		s -> array[orig_idx].val = temp -> array[i].val;
		s -> array[orig_idx].index = i;
		i++;
	}
	stack_free(&temp);
}

static void recombine_stack(s_stack *s, s_stack *positive, s_stack *negative)
{
	int i;
	int j;

	j = 0;
	i = negative -> cnt - 1;
	while (i >= 0)
	{
		s -> array[j] = negative -> array[i];
		s -> array[j].val *= -1;
		j++;
		i--;
	}
	i = 0;
	while (i < positive -> cnt)
	{
		s -> array[j] = positive -> array[i];
		j++;
		i++;
	}
	original_dest(s);
}

void	radix_controller(s_stack *s)
{
	s_stack *positive;
	s_stack *negative;

	stack_create(&positive, s -> cap, 'b');
	stack_create(&negative, s -> cap, 'b');
	if (!positive || !negative)
		return ;
	split_stack(s, positive, negative);
	radix_sort(positive);
	radix_sort(negative);
	recombine_stack(s, positive, negative);
	stack_free(&positive);
	stack_free(&negative);
}
