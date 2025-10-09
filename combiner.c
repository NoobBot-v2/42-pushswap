/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combiner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:28:35 by jsoh              #+#    #+#             */
/*   Updated: 2025/10/09 22:00:58 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_yong_hao_join(char *s1, char const *s2)
{
	size_t	total_len;
	char	*joined_s;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_s = (char *)malloc(total_len);
	if (!joined_s)
		return (NULL);
	ft_strlcpy(joined_s, s1, total_len);
	ft_strlcat(joined_s, s2, total_len);
	free(s1);
	return (joined_s);
}

static int	ft_get_size(int argc, char const **argv)
{
	int	len;
	int	i;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len += ft_strlen(argv[i]);
		i++;
	}
	return (i);
}

//join all, split once
char	**ft_combine(int argc, char const **argv)
{
	int		len;
	int		i;
	char	*main_arr;
	char	**str_arr;

	i = 1;
	main_arr = ft_strdup("");
	len = ft_get_size(argc, argv) + 1;
	while (i < argc)
	{
		main_arr = ft_yong_hao_join(main_arr, argv[i]);
		main_arr = ft_yong_hao_join(main_arr, " ");
		i++;
	}
	str_arr = ft_split(main_arr, ' ');
	free(main_arr);
	return (str_arr);
}
