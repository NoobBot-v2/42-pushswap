/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobdevbot2 <noobdevbot2@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:46:29 by noobdevbot2       #+#    #+#             */
/*   Updated: 2025/09/20 02:06:25 by noobdevbot2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "more_pushswap.h"

int lis_true(s_stack *s, int *tmp) {
    int n = s->cnt;
    int tails[n];  // stores indices of smallest ending value for subsequences
    int prev[n];   // previous index in LIS
    int len = 0;

    for (int i = 0; i < n; i++) {
        prev[i] = -1;

        // Binary search in tails[0..len-1] based on values
        int left = 0, right = len - 1, pos = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (s->array[tails[mid]].index < s->array[i].index)
                left = mid + 1;
            else
                right = mid - 1;
        }
        pos = left;

        if (pos > 0)
            prev[i] = tails[pos - 1];

        tails[pos] = i;

        if (pos == len)
            len++;
    }

    // Reconstruct LIS in original order
    int k = len - 1;
    int idx = tails[len - 1];
    while (idx >= 0) {
        tmp[k--] = s->array[idx].index;
        idx = prev[idx];
    }

    return len; // length of LIS
}

int main(int argc, char const *argv[])
{
    s_stack	*s;

    stack_create(&s, argc, 'a');
	stack_init(s, argv);
    radix_controller(s);
    stack_view(s);
    int *tmp = malloc(s->cap * sizeof(int));
    int lis_len = lis_true(s, tmp);

    printf("LIS length: %d\n", lis_len);
    for (int i = 0; i < lis_len; i++)
        printf("%d ", tmp[i]);
    printf("\n");

    return 0;
}
