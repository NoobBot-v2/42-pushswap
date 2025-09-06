/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:58:27 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/06 19:35:22 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

void	stack_create(s_stack **stack, int size, char type)
{
	(*stack) = (s_stack *)malloc(sizeof(s_stack));
	if (!stack)
		return ;
	(*stack)->array = (s_num *)malloc(size * sizeof(s_num));
	if (!(*stack)->array)
		return ;
	ft_memset((*stack) -> array, 0, size * sizeof(s_num));
	if (type == 'a')
		(*stack)->cnt = size - 1;
	else if (type == 'b')
		(*stack)->cnt = 0;
	(*stack)->cap = size;
}

void	stack_init(s_stack *s, char const *argv[])
{
	int	index;

	index = 0;
	ft_memset(s->array, 0, sizeof(s->array[0]) * s -> cap);
	while (index < s->cnt)
	{
		s -> array[index].val = ft_atoi(argv[index + 1]);
		s -> array[index].index = index;
		index++;
	}
}

void	stack_view(s_stack *s)
{
	int	index;

	index = 0;
	printf("Stack View: %i\n",s -> cnt);
	while (index < s -> cnt)
	{
		printf("num: %-6i idx: %-6i\n",s -> array[index].val, s -> array[index].index);
		index++;
	}
}

void	stack_free(s_stack **stack)
{
	if (!stack || !*stack)
		return ;
	free((*stack)->array);
	free(*stack);
	*stack = NULL;
}
