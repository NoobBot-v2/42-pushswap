/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:56:39 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/31 15:57:02 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char const *argv[])
{
	s_stack *stack_a;
	s_stack *stack_b;

	stack_create(&stack_a, argc, 'a');
	stack_create(&stack_b, argc, 'b');
	stack_init(stack_a, argv);
	push(stack_a,stack_b);
	push(stack_a,stack_b);
	//stack_view(stack_a);
	//stack_view(stack_b);
	master_control(stack_a, stack_b);
	//stack_view(stack_a);
	//stack_view(stack_b);
	return 0;
}

//convert arguments into ints
//int main(int argc, char const *argv[])
//{
//	s_stack *stack_a;
//	s_stack *stack_b;
//	s_pair a;
//	s_pair b;
//	s_rcost cost;

//	cost = (s_rcost){0};
//	stack_create(&stack_a, argc, 'a');
//	stack_create(&stack_b, argc, 'b');
//	stack_init(stack_a, argv);
//	rotate_up(stack_a);
//	rotate_up(stack_a);
//	push(stack_a,stack_b);
//	push(stack_a,stack_b);
//	stack_view(stack_a);
//	stack_view(stack_b);
//	//Unsorted list search .up and .down will be handled by the while loop
//	a = make_pair(get_num_index(-2, stack_a),stack_a -> cnt);
//	b = rotation_cost(3, stack_b);
//	cost = final_cost(&a,&b);
//	ft_view_final_cost(cost);
//	return 0;
//}
