/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheek_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:03:30 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/21 10:28:45 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cheek_arg(t_sem *philo, char **av)
{
	if (av[5] && philo->n_eat == 0)
	{
		printf("philo should be at least 1 time !\n");
		return ;
	}
	if (philo->n_philo < 1 &&  philo->n_philo > 200)
	{
		printf("number of philo should be at least 1 philo  at max 200!\n");
		return ;
	}
	if (!philo->t_die || !philo->t_eat || !philo->t_sleep)
	{
		printf("invalid time !\n");
		return ;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	cheek_nb(char **s, int ac)
{
	int j;
	int i;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][0] == '+')
				j++;
			while (s[i][j] && s[i][j] >= '0' && s[i][j] <= '9')
				j++;
			if (j != ft_strlen(s[i]))
				return (0);
		}
		i++;
	}
	return (1);
}