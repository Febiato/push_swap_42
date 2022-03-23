/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:16:04 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/08 15:24:12 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	int	i;
	int	k;

	k = (int)ft_strlen(s);
	i = 0;
	if (s)
	{
		while (i < k)
		{
			write(2, (unsigned char *)&s[i], 1);
			i++;
		}
	}
}

static void	ft_clean_stack(t_data **stack)
{
	t_data	*lst;

	lst = NULL;
	if ((*stack) != NULL)
	{
		while ((*stack)->next != NULL)
		{
			lst = (*stack)->next;
			free((*stack));
			(*stack) = NULL;
			(*stack) = lst;
		}
		free((*stack));
		(*stack) = NULL;
	}
	free(stack);
	stack = NULL;
}

void	ft_error_exit(char *error, int64_t *arr,
			t_data **stack_a, t_data **stack_b)
{
	if (stack_a != NULL)
		ft_clean_stack(stack_a);
	if (stack_b != NULL)
		ft_clean_stack(stack_b);
	if (error != NULL)
		ft_putstr(error);
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
	exit(1);
}
