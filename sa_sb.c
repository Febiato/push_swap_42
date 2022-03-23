/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:17:29 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/05 22:47:10 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data **stack_a)
{
	int64_t	i;

	write(1, "sa\n", 3);
	i = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = i;
}

void	ft_sb(t_data **stack_b)
{
	int64_t	i;

	write(1, "sb\n", 3);
	i = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = i;
}
