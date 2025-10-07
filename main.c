/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:51:00 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:51:03 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//./push_swap $(seq -100 100 | shuf | head -n 20)
int main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_arr	*lis;

	if (argc == 1)
		return 0;
	stack_create(&stack_b, argc, 'b');
	ft_init(&stack_a, &lis, argc, argv);
	algo_1(stack_a, stack_b, lis);
	algo_2(stack_a, stack_b);
	rotate_to_top(stack_a, get_min_index(stack_a));
	ft_free_all(&stack_a, &stack_b, &lis);
	return 0;
}
