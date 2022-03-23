/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:17:18 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/08 21:04:58 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_data **stack_a, t_data **stack_b)
{
	t_data	*a;
	t_data	*b;
	t_data	*b_new;

	write(1, "pb\n", 3);
	a = (*stack_a);
	b = (*stack_b);
	b_new = (t_data *)malloc(sizeof(t_data));
	if (b_new == NULL)
		ft_error_exit("Error\n", NULL, stack_a, stack_b);
	b_new->value = (*stack_a)->value;
	b_new->next = (*stack_b);
	(*stack_b) = b_new;
	(*stack_a) = (*stack_a)->next;
	free(a);
	a = NULL;
}

void	ft_pa(t_data **stack_a, t_data **stack_b)
{
	t_data	*a;
	t_data	*b;
	t_data	*a_new;

	write(1, "pa\n", 3);
	a = (*stack_a);
	b = (*stack_b);
	a_new = (t_data *)malloc(sizeof(t_data));
	if (a_new == NULL)
		ft_error_exit("Error\n", NULL, stack_a, stack_b);
	a_new->value = (*stack_b)->value;
	a_new->next = (*stack_a);
	(*stack_a) = a_new;
	(*stack_b) = (*stack_b)->next;
	free(b);
	b = NULL;
}
