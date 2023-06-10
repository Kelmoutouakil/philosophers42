/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:35:22 by kelmouto          #+#    #+#             */
/*   Updated: 2023/05/05 08:18:22 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_check(char **av, int ac)
{
	if (ac != 5 && ac != 6)
		return (0);
	if (!cheek_nb(av, ac))
	{
		printf("invalid arguments\n");
		return (-1);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	*philo;

	if (!main_check(av, ac))
		return (-1);
	int c = ft_atoi(av[1]);
	if (c == 0)
		return (-1);
	philo = malloc(sizeof(t_data) * c);
	if (init_philo(philo, av) == -1)
		return (-1);
	while (1)
	{
		if (cheek_death(philo->ph) == 1)
		{
			print("is died", philo->ph, 0);
			break ;
		}
		if (av[5] && philo->count == philo->n_eat)
		{
			ft_destroythread(philo);
			break ;
		}
	}
	return (0);
}
