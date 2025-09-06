/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:38:38 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/06 19:31:04 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

static int	max_digit_count(s_stack *s)
{
	int	max;
	int	digits;

	if (!s)
		return (-1);
	max = get_max_num(s);
	digits = 0;
	while (max > 0)
	{
		max /= 10;
		digits++;
	}
	return (digits);
}

static void	counting_sort(s_stack *s, int prefix[], int digit_place)
{
	int	i;
	int	count[10];

	ft_memset(count, 0, sizeof(count));
	i = 0;
	while (i < s -> cnt)
	{
		count[(s -> array[i].val / digit_place) % 10]++;
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

static void	prefix_sort(s_stack *s1, s_stack *temp, int exp)
{
	int	prefix[10];
	int	i;
	int	digit;

	i = s1 -> cnt - 1;
	ft_memset(prefix, 0, sizeof(prefix));
	counting_sort(s1, prefix, exp);
	while (i >= 0)
	{
		digit = (s1->array[i].val / exp) % 10;
		temp -> array[prefix[digit] - 1] = s1 -> array[i];
		prefix[digit]--;
		i--;
	}
}

void	radix_sort(s_stack *s1)
{
	int		max;
	int		exp;
	int		i;
	s_stack	*temp;

	stack_create(&temp, s1 -> cap, 'b');
	if (!temp)
		return ;
	exp = 1;
	max = -1;
	max = max_digit_count(s1);
	while (max > 0)
	{
		i = 0;
		prefix_sort(s1, temp, exp);
		while (i < s1 -> cnt)
		{
			s1->array[i] = temp->array[i];
			i++;
		}
		exp *= 10;
		max--;
	}
	stack_free(&temp);
}
