/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:01:36 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/10 22:47:18 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo_init(t_sem *philo, char **av)
{
	philo->print = NULL;
	philo->forks = NULL;
	philo->n_philo = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->n_eat = ft_atoi(av[5]) * philo->n_philo;
}

// void	init_arg(t_sem *philo, char **av)
// {
// 	philo->n_philo = ft_atoi(av[1]);
// 	philo->t_die = ft_atoi(av[2]);
// 	philo->t_eat = ft_atoi(av[3]);
// 	philo->t_sleep = ft_atoi(av[4]);
// 	if (av[5])
// 		philo->n_eat = ft_atoi(av[5]);
// }