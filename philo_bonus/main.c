/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:54:18 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/10 22:56:55 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main_check(char **av, int ac)
{
	if (ac != 5 && ac != 6)
		return (0);
	if (!cheek_nb(av, ac))
	{
		printf("invalid arguments\n");
		return (0);
	}
	return (1);
}

void	create_semaphore(t_sem *sem)
{
	sem_unlink("print");
	sem_unlink("forks");
	sem->print = sem_open("print", O_CREAT, 0600, 1);
	sem->forks = sem_open("forks", O_CREAT, 0600, sem->n_philo);
}



void	*check_death(void *p)
{
	t_philo	*s;

	s = (t_philo *)p;
	while (1)
	{
		if (get_time() - s->last_eat >= s->data->t_die)
		{
			print("died", s, 1);
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
		p.last_eat = get_time();
		sem_wait(p.data->print);
		print("is eating", &p, 1);
		sem_post(p.data->print);
		sem_post(p.data->forks);
		sem_post(p.data->forks);
		p.count++;
		if (p.count >= p.data->n_eat)
			exit(0);
		ft_usleep(p.data->t_eat);	
		sem_wait(p.data->print);
		print("is sleeping", &p, 1);
		sem_post(p.data->print);
		ft_usleep(p.data->t_sleep);
		sem_wait(p.data->print);
		print("is thinking", &p, 1);
		sem_post(p.data->print);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_sem	*sem;
	t_philo	*philo;
	
	i = -1;
	sem = malloc(sizeof(t_sem));
	philo = malloc(sizeof(t_philo) * sem->n_philo);
	if (ac == 5 || ac == 6)
	{
		if (!main_check(av, ac))
			return (-1);
		ft_philo_init(sem, av);
		if (cheek_arg(sem, av) == -1)
			return (-1);

		create_semaphore(sem);

		while (++i < sem->n_philo)
		{
			philo[i].index = i + 1;
			philo[i].data = sem;
			philo[i].pid = fork();
			philo[i].data->t_start = get_time();
			philo[i].last_eat = get_time();
			if (philo[i].pid == 0)
			{
				philo_life(philo[i]);
			}
		}
		int a;
		while (1)
		{
			waitpid(-1, &a, 0);
			if (WEXITSTATUS(a) != 0)
			{
				int j = 0;
				while (j < philo->data->n_philo)
					kill(philo[j++].pid, SIGKILL);
				exit(0);
			}
		}
	}
	else
		printf("Error: Too many arguments\n");

	return (0);
}