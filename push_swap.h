/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:17:21 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/09 14:31:26 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data	t_data;

struct s_data
{
	int64_t	value;
	int64_t	count;
	int64_t	flag_a;
	int64_t	flag_b;
	t_data	*next;
	int64_t	min;
	int64_t	max;
	int64_t	median;
};

void	ft_pars(int argc, char **argv, int64_t *arr);
int		ft_strlen(const char *s);
void	ft_error_exit(char *error, int64_t *arr,
			t_data **stack_a, t_data **stack_b);
int64_t	ft_atoi(const char *str, int64_t *arr, int64_t *arr_full);
void	ft_putstr(char *s);
void	ft_check(int i, int64_t *arr, char *argv, int64_t *arr_full);
int		ft_pars_string(int64_t *arr, char *argv, int64_t *arr_full);
char	**ft_split(char const *s, char c, int64_t *int_arr);
void	ft_sort(int64_t *arr, int argc);
void	ft_stack(t_data **stack_a, int64_t *arr, int argc);
void	ft_pre_sort(int64_t *arr, int argc);
void	ft_double_check(int64_t *arr, int argc);
void	ft_put_b(t_data **stack_a, t_data **stack_b, int argc, int64_t *arr);
void	ft_sb(t_data **stack_b);
void	ft_sa(t_data **stack_a);
void	ft_ra(t_data **stack_a);
void	ft_rb(t_data **stack_b);
void	ft_pb(t_data **stack_a, t_data **stack_b);
void	ft_pa(t_data **stack_a, t_data **stack_b);
void	ft_rra(t_data **stack_a);
void	ft_rrb(t_data **stack_b);
void	ft_first_sort(t_data **stack_a);
void	ft_error_memory(t_data **stack_a, t_data **stack_b);
void	ft_b_to_a(t_data **stack_a, t_data **stack_b);
void	ft_count(t_data **stack_a, t_data **stack_b,
			int64_t size_a, int64_t size_b);
int64_t	ft_size(t_data **stack);
int64_t	ft_extra_count(t_data *stack_b, t_data *stack, int64_t size_a);
int64_t	ft_first_count(t_data *first_b, int64_t size, t_data *stack);
void	ft_final(t_data **stack_a, t_data **stack_b);
void	ft_rotate_b(t_data **stack_b, t_data **stack_a, t_data *to_a);
void	ft_rotate_a(t_data **stack_a);
void	ft_extra_rotate_a(t_data **stack_a, int64_t size,
			int64_t min_count, int64_t min);
void	ft_sort_check(int64_t *arr, int argc);
int		ft_search(char const *s, char c, int k);

#endif