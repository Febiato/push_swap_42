/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:17:10 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/09 16:16:20 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_split_argc(int64_t *arr, int argc, char **argv)
{
	int	i;
	int	k;

	k = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_search(argv[i], ' ', 0) == 1)
			ft_check(k, arr, argv[i], arr);
		else
			ft_pars_string(&arr[k], argv[i], arr);
		k += ft_search(argv[i], ' ', 0);
		i++;
	}
	return (k);
}

int	main(int argc, char **argv)
{
	int64_t	*arr;
	int		i;
	int		k;

	k = 0;
	i = 1;
	while (i < argc)
	{
		k += ft_search(argv[i], ' ', 0);
		i++;
	}
	arr = (int64_t *)malloc(sizeof(int64_t) * (k + 1));
	if (!arr)
		ft_error_exit("Error\n", NULL, NULL, NULL);
	k = ft_split_argc(arr, argc, argv);
	if (k + 1 < argc)
		ft_error_exit("Error\n", arr, NULL, NULL);
	ft_pre_sort(arr, k + 1);
}
