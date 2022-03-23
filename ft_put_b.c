/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:43:47 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/09 14:40:58 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_b(t_data **stack_a, t_data **stack_b, int argc, int64_t *arr)
{
	t_data	*i;

	i = NULL;
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
	while ((*stack_a)->next->next->next != NULL)
	{
		if ((*stack_a)->value != (*stack_a)->min
			&& (*stack_a)->value != (*stack_a)->max)
		{
			if ((*stack_a)->value < (*stack_a)->median)
				ft_pb(stack_a, stack_b);
			else
			{
				ft_pb(stack_a, stack_b);
				ft_rb(stack_b);
			}
		}
		else
			ft_ra(stack_a);
	}
	ft_first_sort(stack_a);
}

void	ft_first_sort(t_data **stack_a)
{
	if ((*stack_a)->next->value == (*stack_a)->max)
		ft_rra(stack_a);
	while ((*stack_a)->next->next->value != (*stack_a)->max)
		ft_ra(stack_a);
	while ((*stack_a)->value != (*stack_a)->min)
		ft_sa(stack_a);
}
