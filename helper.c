/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:58:27 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/22 20:53:16 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//sizeof struct later
void stack_create(s_stack **stack, int size, char type)
{
	(*stack) = (s_stack *)malloc(sizeof(s_stack));
	if (!stack)
		return ;
	(*stack)->array = (int *)malloc(size * sizeof(int));
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
//to input all ints into stack a
void stack_init(s_stack *stack, char const *argv[])
{
	int index;

	index = 0;
	while (index < stack->count)
	{
		stack -> array[index] = ft_atoi(argv[index + 1]);
		index++;
	}
}

void stack_view(s_stack *stack)
{
	int index;

	index = 0;
	while (index < stack -> count)
	{
		printf("%i\n",stack -> array[(stack -> start + index) % stack -> capacity]);
		index++;
	}
}