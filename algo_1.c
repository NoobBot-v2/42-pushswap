/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh@student.42singapore.sg <jsoh@stude    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:25:21 by jsoh@studen       #+#    #+#             */
/*   Updated: 2025/08/29 21:25:21 by jsoh@studen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Currently returns number of moves made
//Should return an instruction set
//Push 2 to b before passing
int master_control(s_stack *a, s_stack *b)
{
	int i = 0;
	int num;
	s_pair pair_a;
	s_pair pair_b;
	s_rcost cost;
	s_rcost *arr_cost;

	arr_cost = (s_rcost *)malloc(a -> cap * sizeof(s_rcost));
	if (!arr_cost)
		return (-1);
	while(i < a -> cnt)
	{
		num = a -> array[i];
		printf("Num: %i\n",num);
		pair_a = make_pair(get_num_index(num, a), a -> cnt);
		//pair_b is missing 1 case where incoming number is new max or new min
		pair_b = make_pair(number_dest_posn(num, b), b -> cnt);
		//pair_b = rotation_cost(num, b);
		cost = final_cost(&pair_a, &pair_b);
		arr_cost[i] = cost;
		printf("cost: %3i\n",arr_cost[i].total);
		i++;
	}
	free(arr_cost);
	return 0;
}
