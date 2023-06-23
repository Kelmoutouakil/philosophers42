/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheek_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:03:30 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/23 15:59:31 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_time(t_sem *philo)
{
	if (philo->t_die <= 0 || philo->t_die > INT_MAX)
	{
		printf("invalid time\n");
		return (-1);
	}
	if ((philo->t_eat <= 0 || philo->t_eat > INT_MAX))
	{
		printf("invalid time\n");
		return (-1);
	}
	if ((philo->t_sleep <= 0 || philo->t_sleep > INT_MAX))
	{
		printf("invalid time\n");
		return (-1);
	}
	return (0);
}

int	cheek_arg(t_sem *philo, char **av)
{
	if (philo->n_philo < 1 || philo->n_philo > INT_MAX)
	{
		printf("number of philo should be at least 1 philo  at max 200!\n");
		return (-1);
	}
	else if (av[5] && philo->n_eat == 0)
	{
		printf("philo should be at least 1 time !\n");
		return (-1);
	}
	else if (check_time(philo))
		return (-1);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main_check(char **av, int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("  error of number of arguments\n ");
		return (0);
	}
	if (!cheek_nb(av, ac))
	{
		printf("invalid arguments\n");
		return (0);
	}
	if (ft_atoi(av[1]) > INT_MAX)
		return (0);
	return (1);
}

int	cheek_nb(char **s, int ac)
{
	int	j;
	int	i;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (s && s[i][j])
		{
			if (s[i][0] == '+')
				j++;
			while (s[i][j] && s[i][j] >= '0' && s[i][j] <= '9')
				j++;
			if (j != ft_strlen(s[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
