/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:51:00 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/28 21:10:37 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

//./pushswap $(seq -100 100 | shuf | head -n 20)
int main(int argc, char const *argv[])
{
	s_stack	*stack_a;
	s_stack	*stack_b;
	s_arr	*lis;

	if (argc == 1)
		return 0;
	stack_create(&stack_a, argc, 'a');
	stack_create(&stack_b, argc, 'b');
	stack_init(stack_a, argv);
	radix_controller(stack_a);

	lis = malloc(argc * sizeof(s_arr));
	lis -> array = malloc(stack_a -> cap * sizeof(int));
	for (int i = 0; i < argc; i++)
		lis -> array[i] = 0;
	//stack_view(stack_a);
	lis_controller(stack_a,lis);
	printf("Algo 1\n");
	algo_controller_1(stack_a, stack_b, lis);
	stack_view(stack_a);
	stack_view(stack_b);
	printf("Algo 2\n");
	algo_controller_2(stack_a, stack_b, lis);
	//find_next_gap(stack_a, lis);
	//algo_controller_2(stack_a, stack_b, lis);
	// for (int i = 0; i < argc; i++)
	// 	printf("lis: %2i: %2i\n",i,lis -> array[i]);
	//stack_view(stack_a);
	//stack_view(stack_b);

	free(lis -> array);
	free(lis);
	stack_free(&stack_a);
	return 0;
}
