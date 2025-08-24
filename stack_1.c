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
	(*stack)->array = (s_number *)malloc(size * sizeof(s_number));
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
		stack -> array[index].num = ft_atoi(argv[index + 1]);
		stack -> array[index].dest = -1;
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
			stack -> array[stk_idx].num);
		printf("dest: %-10f\n",
			stack -> array[stk_idx].dest);
		index++;
	}
}

void	stack_dest(s_stack *s_stk)
{
	int	index;
	int	min;
	int	max;
	int	cap;
	int	num;

	num = 0;
	index = 0;
	min = get_min(s_stk);
	max = get_max(s_stk);
	printf("Min: %10i	Max: %i\n", min, max);
	cap = s_stk -> cap;
	while (index < s_stk -> cnt)
	{
		num = s_stk -> array[(s_stk -> start + index) % cap].num;
		s_stk -> array[(s_stk -> start + index) % cap].dest
			= normalize(min, max, num, cap);
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
