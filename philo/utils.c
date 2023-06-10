/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:39:07 by kelmouto          #+#    #+#             */
/*   Updated: 2023/04/27 19:41:30 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(unsigned int t)
{
	long int	time;

	time = get_time();
	while (get_time() - time < t)
		usleep(t / 10);
}

void	print(char *s, t_philo *p, int a)
{
	if (a)
	{
		pthread_mutex_lock(&p->data->print);
		printf("%ld ms %d ", get_time() - p->t_start, p->id);
		printf("%s\n", s);
		pthread_mutex_unlock(&p->data->print);
	}
	else
	{
		pthread_mutex_lock(&p->data->print);
		printf("%ld ms %d ", get_time() - p->t_start, p->id);
		printf("%s\n", s);
	}
}

void	ft_destroythread(t_data *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->n_philo)
		pthread_detach(ptr->tid[i]);
}
