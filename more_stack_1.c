/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:58:27 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 22:04:37 by jsoh             ###   ########.fr       */
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
		(*stack)->cnt = size;
	else if (type == 'b')
		(*stack)->cnt = 0;
	(*stack)->cap = size;
}

int	stack_init(t_stack *s, char const **argv)
{
	int	index;
	int	check;
	int	error;

	error = 0;
	index = 0;
	check = 0;
	ft_memset(s->array, 0, sizeof(s->array[0]) * s -> cap);
	while (index < s->cnt)
	{
		check = ft_not_valid_numbers(argv[index]);
		if (check == 1)
			return (1);
		s -> array[index].val = ft_guarded_atoi(argv[index], &error);
		if (error == 1)
			return (1);
		s -> array[index].index = index;
		index++;
	}
	return (0);
}

void	stack_view(t_stack *s)
{
	int	index;

	index = 0;
	ft_printf("Stack View: %i\n", s -> cnt);
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
