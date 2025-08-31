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
// only works on sorted list like stack b
int binary_search(int num, const s_stack *stk)
{
	int head;
	int left;
	int right;
	int mid;
	int val;

	head = get_min_index(stk);
	left = 0;
	right = stk->cnt;
	while (left < right) {
		mid = (left + right) / 2;
		val = stk->array[(head + mid) % stk->cap];
		if (val <= num)
			left = mid + 1;
		else
			right = mid;
	}
	if (left == stk->cnt)
		left = stk->cnt - 1;
	return (head + left) % stk->cap;
}

int number_dest_posn(const int num, const s_stack *dest_stk)
{
	int i;

	i = 0;
	if (num > get_max_num(dest_stk))
		return (get_max_index(dest_stk));
	else if (num < get_min_num(dest_stk))
		return (get_min_index(dest_stk));
	while (i < dest_stk -> cnt - 1)
	{
		if ((dest_stk -> array[i] < num && num < dest_stk -> array[i + 1]) ||
			(dest_stk -> array[i] > num && num > dest_stk -> array[i + 1]))
			return(i + 1);
		i++;
	}
	if (dest_stk -> array[i++] < num && num < dest_stk -> array[0])
		return (i);
	return (-1);
}

// logical index - call this pair function for every number in a stack
// binary search will only work on stack b
s_pair rotation_cost(int num, const s_stack *stack)
{
	s_pair cost;
	int dest;

	cost = (s_pair){0};
	dest = binary_search(num, stack);
	//printf("Dest: %i\n", dest);
	cost.up = dest;
	cost.down = stack->cnt - dest;
	return (cost);
}

// Returns a struct containing lowest rotation instruction combination
s_rcost final_cost(s_pair *a, s_pair *b)
{
	s_rcost cost_opp;
	s_rcost cost_same_dir;

	//ft_view_pair(*a);
	//ft_view_pair(*b);
	cost_opp = check_opp_cost(a, b);
	cost_same_dir = check_same_dir_cost(a, b);
	if (cost_same_dir.total <= cost_opp.total)
	{
		printf("Same dir Case: %-10i\nOpp dir Case : %-10i\n",cost_same_dir.total, cost_opp.total);
		return (cost_same_dir);
	}
	else
	{
		printf("Same dir Case: %-10i\nOpp dir Case : %-10i\n",cost_same_dir.total, cost_opp.total);
		return (cost_opp);
	}
}

//Make a function to handle index and return s_pair
//Index input is a physical index
//Return pair on physical index
//a.down is always at least 1 even at last index, it requires 1 rr to move the correct index to 1st posn
s_pair make_pair(const int index, const int cnt)
{
	s_pair a;

	a = (s_pair){0};
	a.up = index;
	a.down = cnt - index;
	if (a.down == 0)
		a.down = 1;
	return (a);
}

int get_num_index(const int num, const s_stack *stack)
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
