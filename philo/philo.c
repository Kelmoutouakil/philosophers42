/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:03:44 by kelmouto          #+#    #+#             */
/*   Updated: 2023/05/04 10:02:02 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(void *philo)
{
	t_philo	*p;

	p = ((t_philo *)philo);
	if (p->id % 2 == 0)
		usleep(600);
	while (1)
	{
		pthread_mutex_lock(&p->data->fork[p->index1]);
		print("has taken a fork", p, 1);
		pthread_mutex_lock(&p->data->fork[p->index2]);
		print("has taken a fork", p, 1);
		print("is eating", p, 1);
		p->data->count++;
		ft_usleep(p->data->t_eat);
		pthread_mutex_lock(&p->data->m_time);
		p->last_eat = get_time();
		pthread_mutex_unlock(&p->data->m_time);
		pthread_mutex_unlock(&p->data->fork[p->index2]);
		pthread_mutex_unlock(&p->data->fork[p->index1]);
		print("is sleeping", p, 1);
		ft_usleep(p->data->t_sleep);
		print("is thinking", p, 1);
	}
	return (0);
}

int	init_philo(t_data *philo, char **av)
{
	int	i;

	i = 0;
	init_arg(philo, av);
	if (cheek_arg(philo, av) == -1)
		return (-1);
	philo->ph = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	philo->tid = malloc(sizeof(pthread_t) * philo->n_philo);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->n_philo);
	pthread_mutex_init(&philo->m_time, NULL);
	pthread_mutex_init(&philo->print, NULL);
	ft_get_id(philo);
	philo->count = 0;
	while (i < philo->n_philo)
	{
		philo->ph[i].last_eat = get_time();
		pthread_mutex_init(&philo->fork[i], NULL);
		pthread_create(&philo->tid[i], NULL, &philo_life, &philo->ph[i]);
		i++;
	}
	return (0);
}
