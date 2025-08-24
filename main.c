/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:56:39 by jsoh              #+#    #+#             */
/*   Updated: 2025/08/24 17:41:22 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//convert arguments into ints
int main(int argc, char const *argv[])
{
	s_stack *stack_a;
	s_stack *stack_b;

	stack_create(&stack_a, argc, 'a');
	stack_create(&stack_b, argc, 'b');
	stack_init(stack_a, argv);
	stack_dest(stack_a);
	swap(stack_a);
	printf("Stack A\n");
	stack_view(stack_a);
	printf("Stack B\n");
	stack_view(stack_b);
	return 0;
}
