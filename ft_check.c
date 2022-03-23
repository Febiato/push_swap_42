/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:12 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/09 16:14:42 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_check(int64_t *arr, int argc)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < argc - 2)
	{
		if (arr[i] > arr[i + 1])
			flag = 1;
		if (arr[i] == arr[i + 1])
			ft_error_exit("Error\n", arr, NULL, NULL);
		i++;
	}
	if (flag == 0)
		ft_error_exit(NULL, arr, NULL, NULL);
}

void	ft_double_check(int64_t *arr, int argc)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < argc - 1)
	{
		while (k < i)
		{
			if (arr[i] == arr[k])
				ft_error_exit("Error\n", arr, NULL, NULL);
			k++;
		}
		k = 0;
		i++;
	}
}

int64_t	ft_atoi(const char *str, int64_t *arr, int64_t *arr_full)
{
	int64_t	result;
	int64_t	i;
	int64_t	plus;

	plus = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			plus = -1;
		i++;
	}
	if (str[i] == '\0')
		ft_error_exit("Error\n", arr_full, NULL, NULL);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result * plus > 2147483647 || result * plus < -2147483648)
			ft_error_exit("Error\n", arr_full, NULL, NULL);
		i++;
	}
	return (result * plus);
}

void	ft_check(int i, int64_t *arr, char *argv, int64_t *arr_full)
{
	int	k;
	int	plus;
	int	flag;

	flag = 1;
	plus = 1;
	k = 0;
	while (argv[k] != '\0')
	{
		if ((argv[k] >= '0' && argv[k] <= '9') || argv[k] == ' '
			|| (plus == 1 && flag == 1 && (argv[k] == '+' || argv[k] == '-')))
		{
			if (argv[k] >= '0' && argv[k] <= '9' && flag == 1)
				flag = 0;
			if (argv[k] == '+' || argv[k] == '-')
				plus = 0;
			k++;
		}
		else
			ft_error_exit("Error\n", arr_full, NULL, NULL);
	}
	arr[i] = ft_atoi(argv, arr, arr_full);
	if (arr[i] > 2147483647 || arr[i] < -2147483648)
		ft_error_exit("Error\n", arr_full, NULL, NULL);
}
