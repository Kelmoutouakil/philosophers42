/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:54:18 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/21 17:45:55 by kelmouto         ###   ########.fr       */
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

void	init_arg(t_sem *philo, char **av)
{
	philo->n_philo = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->n_eat = ft_atoi(av[5]) * philo->n_philo;
}

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

void	ft_philo_init(t_sem *philo, char **av)
{
	philo->print = NULL;
	philo->forks = NULL;
	philo->n_philo = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->n_eat = ft_atoi(av[5]);
	//else
		//philo->state = -1;
}

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

int	main(int ac, char **av)
{
	int i;
	t_sem *sem;
	t_philo *philo;

	i = -1;
	sem = malloc(sizeof(t_sem));
	philo = malloc(sizeof(t_philo) * sem->n_philo);
	if (ac == 5 || ac == 6)
	{
		if (!main_check(av, ac))
			return (0);
		ft_philo_init(sem, av);
		//cheek_arg(sem, av);

		create_semaphore(sem);

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
		int a;
		int d = 0;
		while (1)
		{
			waitpid(-1, &a, 0);
			d++;
			if (WEXITSTATUS(a) != 0)
			{
				int j = 0;
				while (j < philo->data->n_philo)
					kill(philo[j++].pid, SIGKILL);
			}
			if (d == philo->data->n_philo)
				exit(0);
		}
	}
	else
		printf("Error: Too many arguments\n");

	return (0);
}