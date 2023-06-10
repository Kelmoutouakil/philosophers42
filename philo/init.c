/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:54:16 by kelmouto          #+#    #+#             */
/*   Updated: 2023/05/04 10:02:30 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(t_data *philo, char **av)
{
	philo->n_philo = ft_atoi(av[1]);
	if (philo->n_philo == 0)
		return ;
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->n_eat = ft_atoi(av[5]) * philo->n_philo;
}

void	ft_get_id(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->n_philo)
	{
		p->ph[i].id = i + 1;
		p->ph[i].data = p;
		if (p->ph[i].id == p->n_philo)
		{
			p->ph[i].index1 = i;
			p->ph[i].index2 = 0;
			p->ph[i].t_start = get_time();
		}
		else
		{
			p->ph[i].index1 = i;
			p->ph[i].index2 = i + 1;
			p->ph[i].t_start = get_time();
		}
		i++;
	}
}
