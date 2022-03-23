/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:17:24 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/05 22:46:33 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_data **stack_a)
{
	t_data	*first;
	t_data	*second;

	write(1, "ra\n", 3);
	first = (*stack_a);
	second = (*stack_a)->next;
	while ((*stack_a)->next != NULL)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = first;
	first->next = NULL;
	(*stack_a) = second;
}

void	ft_rb(t_data **stack_b)
{
	t_data	*first;
	t_data	*second;

	first = (*stack_b);
	second = (*stack_b)->next;
	if ((*stack_b) != NULL && (*stack_b)->next != NULL
		&& (*stack_b)->next->next != NULL)
	{
		write(1, "rb\n", 3);
		while ((*stack_b)->next != NULL)
			(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = first;
		first->next = NULL;
		(*stack_b) = second;
	}
}
