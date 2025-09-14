/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:51:00 by jsoh              #+#    #+#             */
/*   Updated: 2025/09/14 16:33:49 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

//./pushswap $(seq -100 100 | shuf | head -n 20)
int main(int argc, char const *argv[])
{
	s_stack	*stack_a;
	int		*lis_arr;

	if (argc == 1)
		return 0;
	stack_create(&stack_a, argc, 'a');
	stack_init(stack_a, argv);
	radix_controller(stack_a);

	create_array(&lis_arr, argc);
	lis_controller(stack_a, &lis_arr);

	stack_view(stack_a);
	stack_free(&stack_a);
	free(lis_arr);
	return 0;
}
