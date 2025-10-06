/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:51:00 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/06 16:45:10 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

//./pushswap $(seq -100 100 | shuf | head -n 20)
int main(int argc, char const *argv[])
{
	s_stack	*stack_a;
	s_stack	*stack_b;
	s_arr	*lis;
	int grand_total = 0;

	if (argc == 1)
		return 0;
	stack_create(&stack_b, argc, 'b');
	ft_init(&stack_a, &lis, argc, argv);
	//stack_view(stack_a);
	algo_1(stack_a, stack_b, lis, &grand_total);
	algo_2(stack_a, stack_b, lis, &grand_total);
	rotate_to_top(stack_a,get_min_index(stack_a),&grand_total);
	//stack_view(stack_a);
	//stack_view(stack_b);
	ft_free_all(&stack_a, &stack_b, &lis);
	//printf("Grand Total: %3i\n",grand_total);
	return 0;
}
