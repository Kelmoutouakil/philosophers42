/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibft_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:00:51 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/21 23:59:49 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *s)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+')
		i++;
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i++] - '0');
	}
	return (nb);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
