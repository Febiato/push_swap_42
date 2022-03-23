/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:07:14 by cthresh           #+#    #+#             */
/*   Updated: 2022/03/08 21:04:27 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_search_new(char const *s, char c, int k)
{
	while (*s)
	{
		while (*(unsigned char *)s != (unsigned char)c && *s)
		{
			s++;
			k++;
		}
		if (k != 0)
			return (k);
		s++;
	}
	return (0);
}

static void	*ft_free(char **arr, int i, int64_t *int_arr)
{
	int	m;

	m = 0;
	while (m <= i - 1)
	{
		free(arr[m]);
		m++;
	}
	free(arr);
	arr = 0;
	free(int_arr);
	int_arr = NULL;
	ft_error_exit("Error\n", NULL, NULL, NULL);
	return (NULL);
}

static char	*ft_voll(char *arr[0], char *s1, char c)
{
	char	*s2;
	int		i;
	int		k;

	k = 0;
	i = 0;
	s2 = arr[0];
	while ((unsigned char)s1[i] == (unsigned char)c && s1[i])
		i++;
	while ((unsigned char)s1[i] != (unsigned char)c && s1[i])
		s2[k++] = s1[i++];
	s2[k] = '\0';
	if (&s1[i + 1])
		return (&s1[i + 1]);
	return (&s1[i]);
}

int	ft_search(char const *s, char c, int k)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i])
		{
			k++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	return (k);
}

char	**ft_split(char const *s, char c, int64_t *int_arr)
{
	char	**arr;
	char	*s1;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	i = 0;
	k = 0;
	arr = (char **)malloc((ft_search(s, c, k) + 1) * sizeof(char *));
	if (!arr)
		ft_error_exit("Error\n", NULL, NULL, NULL);
	while (i < ft_search(s, c, k))
	{
		arr[i] = (char *)malloc(ft_search_new(s1, c, k) + 1);
		if (!arr[i])
			return (ft_free(arr, i, int_arr));
		s1 = ft_voll(&arr[i], s1, c);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
