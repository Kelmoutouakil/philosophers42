/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:54:18 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/21 23:59:30 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(t_philo *philo, t_sem *sem)
{
	int	i;

	i = -1;
	while (++i < sem->n_philo)
	{
		philo[i].index = i + 1;
		philo[i].data = sem;
		philo[i].pid = fork();
		philo[i].data->t_start = get_time();
		gettimeofday(&philo[i].last_eat, NULL);
		if (philo[i].pid == 0)
		{
			philo_life(philo[i]);
		}
	}
}

void	exit_process(t_philo *philo, t_sem *sem)
{
	int	j;
	int	a;
	int	d;

	d = 0;
	routine(philo, sem);
	while (1)
	{
		waitpid(-1, &a, 0);
		d++;
		if (WEXITSTATUS(a) != 0)
		{
			j = 0;
			while (j < philo->data->n_philo)
				kill(philo[j++].pid, SIGKILL);
		}
		if (d == philo->data->n_philo)
			exit(0);
	}
}

int	main(int ac, char **av)
{
	t_sem	*sem;
	t_philo	*philo;

	sem = malloc(sizeof(t_sem));
	philo = malloc(sizeof(t_philo) * sem->n_philo);
	if (!main_check(av, ac))
		return (0);
	ft_philo_init(sem, av);
	if (cheek_arg(sem, av))
		return (-1);
	create_semaphore(sem);
	exit_process(philo, sem);
	return (0);
}
