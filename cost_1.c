/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:50:59 by jsoh@studen       #+#    #+#             */
/*   Updated: 2025/08/31 17:58:27 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// pivot ++1 to match position to write into
// only works on sorted list like stack b
// should return physical index
	// 1 5
	//list is sorted in descending order 0 -2 5 4 3 2 1
	//start = get_max_index(stk);//min_index returns physical buffer
	//physical index: 2 / logical index: 0
	//end = get_min_index(stk);//max_index returns physical buffer
	//physical index: 1 / logical index: 6
	//physical index = (head + n) % cap for wrapping

int binary_search(int num, const s_stack *stk)
{
	int start = 0;//logical
	int end = stk -> cnt;//logical
	int head = get_max_index(stk);
	int pivot = (end - start)/2;//logical
	int p_pivot = (head + pivot) % stk -> cap;//physical

	// if (num > stk -> array[0])
	// 	return (0);
	// if (num < stk -> array[stk -> cnt - 1])
	// 	return (stk -> cnt - 1);
	//need to handle case if the number is not unique before this search
	while (pivot != start)
	{
		pivot = (end - start)/2;//logical
		p_pivot = (head + pivot) % stk -> cap;//physical
		if (num > stk -> array[p_pivot])//phyiscal
			end = pivot;//logical
		else if (stk -> array[p_pivot] > num)
			start = pivot;
	}
	return (p_pivot);
}

//Is not returning the closest possible bounds to the input num
//2 fits between 0 and 4 as well as -3 and 10
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
		if (dest_stk -> array[i] < num && num < dest_stk -> array[i + 1])
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
		//printf("Same dir Case: %-10i\nother Case : %-10i\n",cost_same_dir.total, cost_opp.total);
		return (cost_same_dir);
	}
	else
	{
		//printf("Opp dir Case : %-10i\nother Case: %-10i\n", cost_opp.total,cost_same_dir.total);
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
