/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:58:27 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/24 16:43:41 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_create(s_stack **stack, int size, char type)
{
	(*stack) = (s_stack *)malloc(sizeof(s_stack));
	if (!stack)
		return ;
	(*stack)->array = (s_number *)malloc(size * sizeof(s_number));
	if (!(*stack)->array)
		return ;
	if (type == 'a')
		(*stack)->count = size - 1;
	else if (type == 'b')
		(*stack)->count = 0;
	(*stack)->start = 0;
	(*stack)->capacity = size;
	printf("Stack created\n");
}

void	stack_init(s_stack *stack, char const *argv[])
{
	int	index;

	index = 0;
	while (index < stack->count)
	{
		stack -> array[index].num = ft_atoi(argv[index + 1]);
		stack -> array[index].dest = -1;
		index++;
	}
}

void	stack_view(s_stack *stack)
{
	int	index;

	index = 0;
	while (index < stack -> count)
	{
		printf("%i\n",
			stack -> array[(stack -> start + index) % stack -> capacity]);
		index++;
	}
}
