/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:16:14 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/08 22:13:32 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pars_string(int64_t *arr, char *argv, int64_t *arr_full)
{
	char	**str_arr;
	int		i;
	int		k;

	k = 0;
	i = 0;
	str_arr = ft_split(argv, ' ', arr);
	while (str_arr[i] != NULL)
	{
		ft_check(i, arr, str_arr[i], arr_full);
		i++;
	}
	k = i;
	while (i >= 0)
	{
		free(str_arr[i]);
		i--;
	}
	free(str_arr);
	str_arr = NULL;
	return (k + 1);
}
