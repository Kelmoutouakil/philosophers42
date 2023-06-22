/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheek.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:55:14 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/22 13:36:29 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cheek_arg(t_data *philo, char **av)
{
	if (av[5] && philo->n_eat == 0)
	{
		printf("philo should be at least 1 time !\n");
		return (-1);
	}
	if (philo->n_philo < 1 || philo->n_philo > 200)
	{
		printf("number of philo should be at least 1 philo  at max 200!\n");
		return (-1);
	}
	if (!philo->t_die || !philo->t_eat || !philo->t_sleep)
	{
		printf("invalid time !\n");
		return (-1);
	}
	return (0);
}

int	cheek_death(t_philo *p)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < p->data->n_philo)
		{
			pthread_mutex_lock(&p->data->m_time);
			if (get_time() - p[i].last_eat >= p->data->t_die)
			{
				pthread_detach(p->data->tid[p->id]);
				pthread_mutex_unlock(&p->data->m_time);
				return (1);
			}
			pthread_mutex_unlock(&p->data->m_time);
			i++;
		}
		return (0);
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
	int	j;
	int	i;

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
