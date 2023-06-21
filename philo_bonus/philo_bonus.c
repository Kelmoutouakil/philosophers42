/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:09:11 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/21 23:59:33 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_semaphore(t_sem *sem)
{
	sem_unlink("print");
	sem_unlink("forks");
	sem->print = sem_open("print", O_CREAT, 0600, 1);
	sem->forks = sem_open("forks", O_CREAT, 0600, sem->n_philo);
}

void	print(char *s, t_philo *p, int a)
{
	if (a != 0)
	{
		sem_wait(p->data->print);
		printf("%ld ms %d ", get_time() - p->data->t_start, p->index);
		printf("%s\n", s);
		sem_post(p->data->print);
	}
	else
	{
		sem_wait(p->data->print);
		printf("%ld ms %d %s\n", get_time() - p->data->t_start, p->index, s);
	}
}

void	*check_death(void *p)
{
	t_philo	*s;

	s = (t_philo *)p;
	while (1)
	{
		if (get_time() - (s->last_eat.tv_sec * 1000 + s->last_eat.tv_usec
				/ 1000) >= s->data->t_die)
		{
			print("died", s, 0);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	philo_life(t_philo p)
{
	pthread_t	death;

	pthread_create(&death, NULL, check_death, &p);
	while (1)
	{
		sem_wait(p.data->forks);
		print("has taken a fork", &p, 1);
		sem_wait(p.data->forks);
		print("has taken a fork", &p, 1);
		gettimeofday(&p.last_eat, NULL);
		print("is eating", &p, 1);
		p.data->n_eat--;
		ft_usleep(p.data->t_eat);
		sem_post(p.data->forks);
		sem_post(p.data->forks);
		if (p.data->n_eat == 0)
			exit(0);
		print("is sleeping", &p, 1);
		ft_usleep(p.data->t_sleep);
		print("is thinking", &p, 1);
		usleep(100);
	}
}
