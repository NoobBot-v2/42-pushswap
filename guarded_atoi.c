/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guarded_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:54:22 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 23:07:44 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	unsigned char	uc_c;

	uc_c = (unsigned char) c;
	return ((uc_c >= '\t' && uc_c <= '\r') || uc_c == ' ');
}

int	ft_guarded_atoi(const char *nptr, int *error)
{
	int			sign;
	long long	number;

	sign = 1;
	number = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while ('0' <= *nptr && *nptr <= '9')
	{
		number *= 10;
		number += (*nptr - '0');
		if (number > INT_MAX || (number * sign) < INT_MIN)
			*error = 1;
		nptr++;
	}
	number *= sign;
	return ((int) number);
}
