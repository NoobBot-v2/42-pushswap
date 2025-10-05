/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:51:00 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/05 17:07:31 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

void rotate_to_top(s_stack *s, int idx, int *grand_total)
{
    if (idx < 0 || idx >= s->cnt)
        return;

    if (idx <= s->cnt / 2)
    {
        // Rotate up
        for (int i = 0; i < idx; i++)
        {
            rotate_up(s);
            (*grand_total)++;
        }
    }
    else
    {
        // Rotate down
        for (int i = 0; i < s->cnt - idx; i++)
        {
            rotate_down(s);
            (*grand_total)++;
        }
    }
}

//./pushswap $(seq -100 100 | shuf | head -n 20)
int main(int argc, char const *argv[])
{
	s_stack	*stack_a;
	s_stack	*stack_b;
	s_arr	*lis;
	int grand_total = 0;

	if (argc == 1)
		return 0;
	stack_create(&stack_a, argc, 'a');
	stack_create(&stack_b, argc, 'b');
	stack_init(stack_a, argv);
	radix_controller(stack_a);
	ft_init_arr(&lis, stack_a -> cap);
	//printf("Original\n");
	//stack_view(stack_a);
	lis_controller(stack_a,lis);
	//printf("LIS\n");
	stack_view(stack_a);
	printf("Algo 1\n");
	algo_1(stack_a, stack_b, lis, &grand_total);
	for (int j = 0; j < argc; j++)
	{
		if(lis -> array[j])
			printf("num: %-3i lis: %-3i\n",j, lis -> array[j]);
	}
	//stack_view(stack_a);
	//stack_view(stack_b);
	printf("Algo 2\n");
	algo_2(stack_a, stack_b, lis, &grand_total);
	rotate_to_top(stack_a,get_min_index(stack_a),&grand_total);
	stack_view(stack_a);
	stack_view(stack_b);
	printf("Grand Total: %3i\n",grand_total);
	free(lis -> array);
	free(lis);
	stack_free(&stack_a);
	stack_free(&stack_b);
	return 0;
}
