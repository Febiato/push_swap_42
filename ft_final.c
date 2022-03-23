/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:16:11 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/05 22:39:32 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final(t_data **stack_a, t_data **stack_b)
{
	int64_t	cou;
	t_data	*first;
	t_data	*to_a;

	cou = (*stack_b)->count;
	to_a = (*stack_b);
	first = (*stack_b);
	while ((*stack_b)->next != NULL)
	{
		(*stack_b) = (*stack_b)->next;
		if (cou > (*stack_b)->count)
		{
			cou = (*stack_b)->count;
			to_a = (*stack_b);
		}
	}
	(*stack_b) = first;
	ft_rotate_b(stack_b, stack_a, to_a);
}

void	ft_rotate_b(t_data **stack_b, t_data **stack_a, t_data *to_a)
{
	while ((*stack_b)->value != to_a->value)
	{
		if (to_a->flag_b == 1)
			ft_rb(stack_b);
		if (to_a->flag_b == -1)
			ft_rrb(stack_b);
		to_a->count--;
	}
	while (to_a->count > 1)
	{
		if (to_a->flag_a == 1)
			ft_ra(stack_a);
		if (to_a->flag_a == -1)
			ft_rra(stack_a);
		to_a->count--;
	}
	ft_pa(stack_a, stack_b);
}

void	ft_rotate_a(t_data **stack_a)
{
	int64_t	min;
	t_data	*first;
	int64_t	size;
	int64_t	min_count;

	min_count = 0;
	size = 0;
	min = (*stack_a)->value;
	first = (*stack_a);
	while ((*stack_a) != NULL)
	{
		if (min > (*stack_a)->value)
		{
			min = (*stack_a)->value;
			min_count = size;
		}
		(*stack_a) = (*stack_a)->next;
		size++;
	}
	(*stack_a) = first;
	ft_extra_rotate_a(stack_a, size, min_count, min);
}

void	ft_extra_rotate_a(t_data **stack_a, int64_t size,
	int64_t min_count, int64_t min)
{
	while ((*stack_a)->value != min)
	{
		if (size - min_count > min_count)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}
