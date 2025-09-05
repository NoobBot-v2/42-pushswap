// /* ************************************************************************** */
// /*																			*/
// /*														:::	  ::::::::   */
// /*   test_LIS.c										 :+:	  :+:	:+:   */
// /*													+:+ +:+		 +:+	 */
// /*   By: jsoh <jsoh@student.42.fr>				  +#+  +:+	   +#+		*/
// /*												+#+#+#+#+#+   +#+		   */
// /*   Created: 2025/09/05 19:25:25 by jsoh			  #+#	#+#			 */
// /*   Updated: 2025/09/05 19:25:34 by jsoh			 ###   ########.fr	   */
// /*																			*/
// /* ************************************************************************** */

// #include "pushswap.h"

// int LIS(int *s, int size, int offset)
// {
// 	int i = 0;
// 	int length = 1;
// 	int last_max;
// 	i = i + offset;
// 	last_max = s[i];
// 	//size = 10 - 2 = 8
// 	//i = 7
// 	printf("--------------------\n");
// 	while (i < size)
// 	{
// 		if (last_max < s[i])
// 		{
// 			printf("%-3i\n",last_max);
// 			last_max = s[i];
// 			length++;
// 		}
// 		i++;
// 	}
// 	printf("%-3i\n",last_max);
// 	printf("--------------------\n");
// 	return (length);
// }

// //Find the elements that were skipped in the LIS
// void find_unsorted_subsequence(int *s, int lis_idx, int size)
// {
// 	int start = -1;
// 	int end = -1;
// 	int i = 1;

// 	while(i < size - 1)
// 	{
// 		if (start == -1 && (s[i] < s[i - 1]))
// 			start = i;
// 		else if (start != -1 && end == -1 && (s[i] < s[i+1]))
// 			end = i;
// 		i++;
// 	}
// 	printf("Start: %-3i End: %-3i\n",start,end);
// }

// int main()
// {

// 	// int test[20] = { -20, 0, 1, 5, 10,
// 	//				 28, -30, 6,
// 	//				 8, -100, -3, 43, 42,
// 	//				 1230, -432, 321, -1, 12, -2 ,4};
// 	int test[20] = {-432,321
// 					,-1,12,-2,4,-20
// 					,0,1,5,10,28,42,43,1230};
// 	int size = 15;
// 	int i = 0;
// 	int length = 1;
// 	int longest_len = 1;
// 	int longest_i = 0;
	
// 	while (i < size)
// 	{
// 		length = LIS(test, size, i);
// 		if (length > longest_len)
// 		{
// 			longest_len = length;
// 			longest_i = i;
// 		}
// 		if (longest_len > (size - i))
// 			break ;
// 		i++;
// 	}
// 	printf("longest_len: %-3i\n",longest_len);
// 	printf("longest_start_idx: %-3i\n",longest_i);
// 	find_unsorted_subsequence(test, longest_i, size);
// 	return 0;
// }
