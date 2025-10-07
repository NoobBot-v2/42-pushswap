/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:58:27 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:51:35 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_create(t_stack **stack, int size, char type)
{
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return ;
	(*stack)->array = (t_num *)malloc(size * sizeof(t_num));
	if (!(*stack)->array)
		return ;
	ft_memset((*stack)-> array, 0, size * sizeof(t_num));
	if (type == 'a')
		(*stack)->cnt = size - 1;
	else if (type == 'b')
		(*stack)->cnt = 0;
	(*stack)->cap = size;
}

void	stack_init(t_stack *s, char const *argv[])
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

void	stack_view(t_stack *s)
{
	int	index;

	index = 0;
	printf("Stack View: %i\n", s -> cnt);
	while (index < s -> cnt)
	{
		ft_printf("p_idx: %-5i num: %-5i idx: %-5i\n", index,
			s -> array[index].val, s -> array[index].index);
		index++;
	}
}

void	stack_free(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	free((*stack)->array);
	free(*stack);
	*stack = NULL;
}
