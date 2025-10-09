/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:51:00 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/09 23:37:33 by jsoh             ###   ########.fr       */
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
	else if (a -> cnt == 4 || a -> cnt == 5)
		ft_5_sort(a, b);
	else
	{
		algo_1(a, b, lis);
		algo_2(a, b);
	}
	rotate_to_top(a, get_min_index(a));
}

static void	ft_init_ptrs(t_stack **a, t_stack **b, t_arr **lis)
{
	*a = NULL;
	*b = NULL;
	*lis = NULL;
}

//./push_swap $(seq -100 100 | shuf | head -n 20)
int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_arr	*lis;
	int		status;

	ft_init_ptrs(&stack_a, &stack_b, &lis);
	status = 0;
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	if (ft_init(&stack_a, &lis, argc, argv))
		status = 1;
	else if (ft_check_dupes(stack_a))
		status = 1;
	else
	{
		stack_create(&stack_b, stack_a->cap, 'b');
		algo_controller(stack_a, stack_b, lis);
	}
	ft_free_all(&stack_a, &stack_b, &lis);
	if (status)
		ft_error_msg();
	return (0);
}
