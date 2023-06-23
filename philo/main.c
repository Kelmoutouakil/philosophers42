/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:35:22 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/23 16:17:27 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_check(char **av, int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("error of number of arguments\n");
		return (0);
	}
	if (!cheek_nb(av, ac))
	{
		printf("invalid arguments\n");
		return (0);
	}
	return (1);
}

t_data	*alloc_philo(char **av)
{
	t_data	*philo;
	int		c;

	c = ft_atoi(av[1]);
	if (c == 0 || c > 2147483646)
		return (NULL);
	philo = malloc(sizeof(t_data) * c);
	if (!philo)
		return (NULL);
	return (philo);
}

int	main(int ac, char *av[])
{
	int		j;
	t_data	*philo;

	if (!main_check(av, ac))
		return (-1);
	philo = alloc_philo(av);
	if (!philo || init_philo(philo, av) == -1)
		return (-1);
	while (1)
	{
		if (cheek_death(philo->ph) == 1)
		{
			print("is died", philo->ph, 0);
			break ;
		}
		pthread_mutex_lock(&philo->countt);
		j = philo->count;
		pthread_mutex_unlock(&philo->countt);
		if (av[5] && j == philo->n_eat)
		{
			ft_destroythread(philo);
			break ;
		}
	}
	return (0);
}
