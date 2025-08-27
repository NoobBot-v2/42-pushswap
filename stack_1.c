/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:58:27 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/24 19:37:01 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_create(s_stack **stack, int size, char type)
{
	(*stack) = (s_stack *)malloc(sizeof(s_stack));
	if (!stack)
		return ;
	(*stack)->array = (int *)malloc(size * sizeof(int));
	if (!(*stack)->array)
		return ;
	if (type == 'a')
		(*stack)->cnt = size - 1;
	else if (type == 'b')
		(*stack)->cnt = 0;
	(*stack)->start = 0;
	(*stack)->cap = size;
	printf("Stack created\n");
}

void	stack_init(s_stack *stack, char const *argv[])
{
	int	index;

	index = 0;
	while (index < stack->cnt)
	{
		stack -> array[index] = ft_atoi(argv[index + 1]);
		index++;
	}
}

void	stack_view(s_stack *stack)
{
	int	index;
	int	stk_idx;

	index = 0;
	stk_idx = (stack -> start + index) % stack -> cap;
	printf("%i\n",stack -> cnt);
	while (index < stack -> cnt)
	{
		stk_idx = (stack -> start + index) % stack -> cap;
		printf("num: %-10i	",
			stack -> array[stk_idx]);
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
