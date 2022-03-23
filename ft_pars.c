/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:16:17 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/09 00:02:56 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	unsigned long	size;
	int				i;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

void	ft_pars(int argc, char **argv, int64_t *arr)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		ft_check(i, arr, argv[i + 1], arr);
		i++;
	}
	ft_sort_check(arr, argc);
}
