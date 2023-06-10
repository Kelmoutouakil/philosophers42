/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:40:49 by kelmouto          #+#    #+#             */
/*   Updated: 2023/05/06 16:44:41 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		usleep(100);
}
void	print(char *s, t_philo *p, int a)
{
	if (a)
	{
		sem_wait(p->data->print);
		printf("%ld ms %d ", get_time() - p->data->t_start, p->index);
		printf("%s\n", s);
		sem_post(p->data->print);
	}
	else
	{
		sem_wait(p->data->print);
		printf("%ld ms %d ", get_time() - p->data->t_start, p->index);
		printf("%s\n", s);
	}
}