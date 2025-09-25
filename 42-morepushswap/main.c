/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:51:00 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/25 11:55:52 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

//./pushswap $(seq -100 100 | shuf | head -n 20)
int main(int argc, char const *argv[])
{
	s_stack	*stack_a;
	s_arr	*lis;

	if (argc == 1)
		return 0;
	stack_create(&stack_a, argc, 'a');
	stack_init(stack_a, argv);
	radix_controller(stack_a);
	stack_view(stack_a);

	lis = malloc(argc * sizeof(s_arr));
	lis -> array = malloc(stack_a -> cap * sizeof(int));
	lis_controller(stack_a,lis);
	for (int i = 0; i < stack_a -> cap; i++)
		printf("%3i : %-3i\n",i, lis -> array[i]);

	stack_free(&stack_a);
	return 0;
}
