/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:01:36 by kelmouto          #+#    #+#             */
/*   Updated: 2023/05/02 16:11:44 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	init_arg(t_sem *philo, char **av)
// {
// 	philo->n_philo = ft_atoi(av[1]);
// 	philo->t_die = ft_atoi(av[2]);
// 	philo->t_eat = ft_atoi(av[3]);
// 	philo->t_sleep = ft_atoi(av[4]);
// 	if (av[5])
// 		philo->n_eat = ft_atoi(av[5]) * philo->n_philo;
// }

// void	ft_get_id(t_data *p)
// {
// 	int	i;

// 	i = 0;
// 	while (i < p->n_philo)
// 	{
// 		p->ph[i].id = i + 1;
// 		p->ph[i].data = p;
// 		if (p->ph[i].id == p->n_philo)
// 		{
// 			p->ph[i].index1 = i;
// 			p->ph[i].index2 = 0;
// 			p->ph[i].t_start = get_time();
// 		}
// 		else
// 		{
// 			p->ph[i].index1 = i;
// 			p->ph[i].index2 = i + 1;
// 			p->ph[i].t_start = get_time();
// 		}
// 		i++;
// 	}
// }