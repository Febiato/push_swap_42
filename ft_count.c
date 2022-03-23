/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:16:00 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/05 22:38:25 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count(t_data **stack_a, t_data **stack_b,
	int64_t size_a, int64_t size_b)
{
	t_data	*first_b;
	t_data	*first_a;
	int64_t	i;

	i = 0;
	first_a = (*stack_a);
	first_b = (*stack_b);
	while ((*stack_b) != NULL)
	{
		i = ft_first_count(first_b, size_b, (*stack_b));
		(*stack_b)->count = i + ft_extra_count((*stack_b), (*stack_a), size_a);
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = first_b;
}

int64_t	ft_size(t_data **stack)
{
	t_data	*first;
	int64_t	size;

	size = 0;
	first = (*stack);
	while ((*stack) != NULL)
	{
		size++;
		(*stack) = (*stack)->next;
	}
	(*stack) = first;
	return (size);
}

int64_t	ft_extra_count(t_data *stack_b, t_data *stack, int64_t size_a)
{
	int64_t	i;

	i = 0;
	while (stack && stack->value > stack_b->value)
	{
		stack = stack->next;
		i++;
	}
	while (stack && stack->value < stack_b->value)
	{
		stack = stack->next;
		i++;
	}
	if (stack == NULL)
		i = 0;
	if (size_a - i > i)
		stack_b->flag_a = 1;
	else
	{
		i = - (i - size_a);
		stack_b->flag_a = -1;
	}
	return (i);
}

int64_t	ft_first_count(t_data *first_b, int64_t size, t_data *stack)
{
	int64_t	i;

	i = 0;
	while (stack->value != first_b->value)
	{
		first_b = first_b->next;
		i++;
	}
	if (size - i > i)
		stack->flag_b = 1;
	else
	{
		i = - (i - size);
		stack->flag_b = -1;
	}
	return (i + 1);
}
