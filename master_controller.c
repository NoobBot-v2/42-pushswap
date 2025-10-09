/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:41:10 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/10/09 21:53:35 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_arr_len(char const **s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_free_str_arr(const char **s)
{
	int	i;

	if (!s)
		return ;
	i = ft_arr_len(s) - 1;
	while (i >= 0)
	{
		if (s[i])
			free((char *)s[i]);
		i--;
	}
	free((char **)s);
}

int	ft_init(t_stack **a, t_arr **lis, int argc, char const **argv)
{
	char	**str_arr;

	*a = NULL;
	*lis = NULL;
	str_arr = ft_combine(argc, argv);
	stack_create(a, ft_arr_len((const char **)str_arr), 'a');
	if (stack_init(*a, (const char **)str_arr))
	{
		ft_free_str_arr((const char **)str_arr);
		return (1);
	}
	ft_free_str_arr((const char **)str_arr);
	radix_controller(*a);
	ft_init_arr(lis, (*a)-> cap);
	lis_controller(*a,*lis);
	return (0);
}

void	ft_free_all(t_stack **a, t_stack **b, t_arr **lis)
{
	if (lis && *lis)
	{
		ft_free_arr(lis);
		*lis = NULL;
	}
	if (a && *a)
	{
		stack_free(a);
		*a = NULL;
	}
	if (b && *b)
	{
		stack_free(b);
		*b = NULL;
	}
}
