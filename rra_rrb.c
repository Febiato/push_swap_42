/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:17:27 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/05 22:46:57 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_data **stack_a)
{
	t_data	*first;
	t_data	*prv_last;

	write(1, "rra\n", 4);
	first = (*stack_a);
	while ((*stack_a)->next->next != NULL)
		(*stack_a) = (*stack_a)->next;
	prv_last = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	prv_last->next = NULL;
	(*stack_a)->next = first;
}

void	ft_rrb(t_data **stack_b)
{
	t_data	*first;
	t_data	*prv_last;

	first = (*stack_b);
	if ((*stack_b) && (*stack_b)->next)
	{
		write(1, "rrb\n", 4);
		while ((*stack_b)->next->next != NULL)
			(*stack_b) = (*stack_b)->next;
		prv_last = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		prv_last->next = NULL;
		(*stack_b)->next = first;
	}
}
