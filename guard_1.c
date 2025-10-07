/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guard_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:09:18 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 15:25:03 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_not_valid_numbers(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_dupes(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->cnt)
	{
		j = i + 1;
		while (j < s->cnt)
		{
			if (s->array[i].val == s->array[j].val)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
