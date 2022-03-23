/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:16:22 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/09 14:40:26 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_elem(int64_t *arr)
{
	if (arr[0] < arr[1])
		ft_error_exit(NULL, arr, NULL, NULL);
	if (arr[0] > arr[1])
	{
		write(1, "sa\n", 3);
		ft_error_exit(NULL, arr, NULL, NULL);
	}
	if (arr[0] == arr[1])
		ft_error_exit("Error\n", arr, NULL, NULL);
}

static void	ft_min_max(int64_t *arr, t_data **stack_a, int argc)
{
	int		i;
	t_data	*min_max;

	i = 0;
	min_max = (*stack_a);
	(*stack_a)->min = arr[0];
	(*stack_a)->max = arr[0];
	(*stack_a)->median = arr[0];
	(*stack_a)->median = arr[(argc - 2) / 2];
	while (i < argc - 1)
	{
		if ((*stack_a)->max < arr[i])
			(*stack_a)->max = arr[i];
		if ((*stack_a)->min > arr[i])
			(*stack_a)->min = arr[i];
		i++;
	}
	while ((*stack_a)->next != NULL)
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->min = min_max->min;
		(*stack_a)->max = min_max->max;
		(*stack_a)->median = min_max->median;
	}
	(*stack_a) = min_max;
}

void	ft_arr_sort(int64_t *arr, int argc)
{
	int		i;
	int64_t	k;

	k = 0;
	i = 0;
	while (argc - 1 >= 0)
	{
		while (i < argc - 2)
		{
			if (arr[i] > arr[i + 1])
			{
				k = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = k;
			}
			i++;
		}
		i = 0;
		argc--;
	}
}

void	ft_stack(t_data **stack_a, int64_t *arr, int argc)
{
	t_data	*he;
	int		i;

	i = 0;
	(*stack_a) = (t_data *)malloc(sizeof(t_data));
	if ((*stack_a) == NULL)
		ft_error_exit("Error\n", arr, NULL, NULL);
	he = (*stack_a);
	while (i < argc - 1)
	{
		(*stack_a)->value = arr[i];
		if (i < argc - 2)
		{
			(*stack_a)->next = (t_data *)malloc(sizeof(t_data));
			if ((*stack_a)->next == NULL)
				ft_error_exit("Error\n", arr, stack_a, NULL);
			(*stack_a) = (*stack_a)->next;
		}
		else
			(*stack_a)->next = NULL;
		i++;
	}
	(*stack_a) = he;
}

void	ft_pre_sort(int64_t *arr, int argc)
{
	t_data	**stack_a;
	t_data	**stack_b;

	ft_sort_check(arr, argc);
	ft_double_check(arr, argc);
	if (argc == 3)
		ft_sort_elem(arr);
	stack_a = (t_data **)malloc(sizeof(t_data *));
	if (stack_a == NULL)
		ft_error_exit("Error\n", arr, NULL, NULL);
	stack_b = (t_data **)malloc(sizeof(t_data *));
	if (stack_b == NULL)
		ft_error_exit("Error\n", arr, stack_a, NULL);
	(*stack_b) = NULL;
	ft_stack(stack_a, arr, argc);
	ft_arr_sort(arr, argc);
	ft_min_max(arr, stack_a, argc);
	ft_put_b(stack_a, stack_b, argc, arr);
	while ((*stack_b) != NULL)
	{
		ft_count(stack_a, stack_b, ft_size(stack_a), ft_size(stack_b));
		ft_final(stack_a, stack_b);
	}
	ft_rotate_a(stack_a);
	ft_error_exit(NULL, NULL, stack_a, stack_b);
}
