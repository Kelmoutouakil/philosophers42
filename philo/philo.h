/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:36:24 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/22 13:36:46 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct l_philo
{
	int				id;
	int				index1;
	int				index2;
	unsigned long	t_start;
	unsigned long	last_eat;
	struct l_data	*data;
}					t_philo;

typedef struct l_data
{
	int				philo_eat;
	int				n_philo;
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	pthread_t		*tid;
	int				count;
	int				n_eat;
	struct l_philo	*ph;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_time;
	pthread_mutex_t	print;
}					t_data;

int					ft_isdigit(int c);
int					cheek_nb(char **s, int ac);
int					ft_atoi(const char *s);
int					ft_isdigit(int c);
int					cheek_death(t_philo *p);
void				ft_putstr(char *s);
int					cheek_arg(t_data *philo, char **av);
void				init_arg(t_data *philo, char **av);
void				ft_get_id(t_data *p);
unsigned long		get_time(void);
void				ft_usleep(unsigned int t);
void				print(char *s, t_philo *p, int a);
void				ft_destroythread(t_data *ptr);
int					init_philo(t_data *philo, char **av);
void				*philo_life(void *philo);

#endif
