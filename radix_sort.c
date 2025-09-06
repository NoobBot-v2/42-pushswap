/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:48:22 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/06 17:27:54 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Radix sort struct array where this struct array maintains its own original index
int max_digit_count(s_stack *s)
{
	int max;
	int digits;

	max = get_max_num(s);
	digits = 1;
	while (max > 0)
	{
		max = max % 10;
		digits++;
	}
	return (digits);
}

void counting_sort(s_stack *s,int prefix[], int digit_place)
{
	int i;
	int count[10] = {0};

	i = 0;
	while (i < s -> cnt)
	{
		count[(s -> test_array[i].val / digit_place) % 10]++;
		i++;
	}
	prefix[0] = count[0];
	i = 1;
	while (i < 10)
	{
		prefix[i] = prefix[i - 1] + count[i];
		i++;
	}
}

void radix_sort(s_stack *s)
{
	int prefix[10];
	int digits;
	int exp;
	int i;

	i = s -> cnt;
	exp = 1;
	digits = max_digit_count(s);
	while (digits > 0)
	{
		ft_memset(prefix, 0, sizeof(prefix));
		counting_sort(s, prefix, exp);
		while (i >= 0)
		{
			s -> test_array[i];
			i--;
		}
		exp *= 10;
		digits--;
	}
}
