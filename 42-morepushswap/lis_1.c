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

static void	init_lis_array(int **lis, int **tmp, int size)
{
	if (size <= 0)
	{
		(*lis) = NULL;
		(*tmp) = NULL;
		return ;
	}
	(*lis) = (int *)malloc(size * sizeof(int));
	if (!(*lis))
		return ;
	(*tmp) = (int *)malloc(size * sizeof(int));
	if (!(*tmp))
		return ;
}

static void	copy_array(int **lis, int **tmp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		(*lis)[i] = (*tmp)[i];
		i++;
	}
}

//Returns the len of the lis
static int	ft_lis(int **tmp, int offset, s_stack *s)
{
	int	i;
	int	j;
	int	last_num;

	if (!*tmp)
		return (0);
	j = 0;
	i = 0 + offset;
	last_num = s -> array[i].index;
	(*tmp)[j++] = last_num;
	printf("ft_lis\n");
	while (i < s -> cnt)
	{
		if (s -> array[i].index > last_num)
		{
			last_num = s -> array[i].index;
			printf("%i\n", last_num);
			(*tmp)[j] = last_num;
			j++;
		}
		i++;
	}
	return (j);
}

int	*lis_controller(s_stack *s)
{
	int	*lis;
	int	*tmp;
	int	i;
	int	len;
	int	longest_len;

	i = 0;
	len = 0;
	longest_len = 0;
	init_lis_array(&lis, &tmp, s -> cap);
	while (i < s -> cnt)
	{
		len = ft_lis(&tmp, i, s);
		if(len > longest_len)
		{
			copy_array(&lis, &tmp, len);
			longest_len = len;
		}
		i++;
	}
	free(tmp);
	return (lis);
}
