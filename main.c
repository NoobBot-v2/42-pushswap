/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:51:00 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/07 17:06:56 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_controller(t_stack *a, t_stack *b, t_arr *lis)
{
	if (lis -> n == a -> cnt)
	{
		rotate_to_top(a, get_min_index(a));
		return ;
	}
	if (a -> cnt == 3)
		ft_3_sort(a);
	else if (a -> cnt == 5)
		ft_5_sort(a, b);
	else
	{
		algo_1(a, b, lis);
		algo_2(a, b);
	}
	rotate_to_top(a, get_min_index(a));
}

//./push_swap $(seq -100 100 | shuf | head -n 20)
int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_arr	*lis;

	stack_b = NULL;
	if (argc == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ft_init(&stack_a, &lis, argc, argv))
	{
		ft_free_all(&stack_a, &stack_b, &lis);
		ft_printf("Error\n");
		return (0);
	}
	if (ft_check_dupes(stack_a))
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_create(&stack_b, stack_a -> cap, 'b');
	algo_controller(stack_a, stack_b, lis);
	ft_free_all(&stack_a, &stack_b, &lis);
	return (0);
}
