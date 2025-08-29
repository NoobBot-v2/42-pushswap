/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh@student.42singapore.sg <jsoh@stude    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:50:59 by jsoh@studen       #+#    #+#             */
/*   Updated: 2025/08/29 18:50:59 by jsoh@studen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// pivot ++1 to match position to write into
// returns logical index
// only works on sorted list like stack b
int ft_binary_search(int num, const s_stack *stack)
{
	int start;
	int end;
	int pivot;
	int p_pivot;

	start = get_min_index(stack);
	end = start + stack->cnt;
	while (start < end)
	{
		pivot = (start + end) / 2;
		p_pivot = pivot % stack->cap;
		if (stack->array[p_pivot] < num)
			start = pivot + 1;
		else
			end = pivot;
	}
	if (start % stack -> cap == stack -> cnt)
		return (0);
	return start % stack->cap;
}

// logical index - call this pair function for every number in a stack
// binary search will only work on stack b
s_pair ft_rotation_cost(int num, const s_stack *stack)
{
	s_pair cost;
	int dest;

	cost = (s_pair){0};
	dest = ft_binary_search(num, stack);
	cost.up = dest;
	cost.down = stack->cnt - dest;
	return (cost);
}

s_pair ft_unsorted_rotation_cost(int num, const s_stack *stack)
{
	s_pair cost;
	int dest;

	cost = (s_pair){0};
	dest = number_dest_posn(num, stack);
	cost.up = dest;
	cost.down = stack->cnt - dest;
	return (cost);
}

// Returns a struct containing lowest rotation instruction combination
s_rcost ft_final_cost(s_pair *a, s_pair *b)
{
	s_rcost cost_zero;
	s_rcost cost_opp;
	s_rcost cost_same_dir;

	cost_zero = check_zero(a, b);
	cost_opp = check_opp_cost(a, b);
	cost_same_dir = check_same_dir_cost(a, b);
	if (cost_zero.total <= cost_opp.total && cost_zero.total <= cost_same_dir.total)
		return (cost_zero);
	else if (cost_same_dir.total <= cost_zero.total && cost_same_dir.total <= cost_opp.total)
		return (cost_same_dir);
	else
		return (cost_opp);
}

//Returns physical index - This finds the number's index
int number_dest_posn(const int num, const s_stack *dest_stk)
{
	int i;

	i = 0;
	while (i < dest_stk -> cnt - 1)
	{
		if (dest_stk -> array[i] < num && num < dest_stk -> array[i + 1])
			return (i + 1);
		if (dest_stk -> array)
		i++;
	}
	if (dest_stk -> array[i] < num && num < dest_stk -> array[0])
		return (0);
	return (-1);
}

//Make a function to handle index and return s_pair
//Index input is a physical index
//Return pair on physical index
s_pair get_up_down(const int index, const int cnt)
{
	s_pair a;

	printf("input i:%i\n",index);
	a.up = index;
	a.down = cnt - index;
	return (a);
}

int get_number_index(const int num, const s_stack *stack)
{
	int index;

	index = 0;
	while (index < stack -> cnt)
	{
		if (stack -> array[index] == num)
			return (index);
		index++;
	}
	return (-1);
}
