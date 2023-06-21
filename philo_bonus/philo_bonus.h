/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:00:39 by kelmouto          #+#    #+#             */
/*   Updated: 2023/06/22 00:00:16 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define SEM_NAME

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_sem
{
	sem_t			*forks;
	sem_t			*print;
	sem_t			*died;
	unsigned long	start;
	int				n_philo;
	unsigned long	t_die;
	int				n_eat;
	unsigned long	t_sleep;
	unsigned long	t_eat;
	unsigned long	t_start;

}					t_sem;

typedef struct s_philo
{
	struct s_sem	*data;
	pid_t			pid;
	struct timeval	last_eat;
	int				index;
}					t_philo;

int					cheek_arg(t_sem *philo, char **av);
int					cheek_nb(char **s, int ac);
int					ft_strlen(char *s);
int					ft_atoi(const char *s);
int					check_time(t_sem *philo);
int					main_check(char **av, int ac);
void				philo_life(t_philo p);
void				*check_death(void *p);
void				print(char *s, t_philo *p, int a);
void				create_semaphore(t_sem *sem);
void				ft_philo_init(t_sem *philo, char **av);
void				init_arg(t_sem *philo, char **av);
void				ft_usleep(unsigned int t);
unsigned long		get_time(void);
void				exit_process(t_philo *philo, t_sem *sem);
void				routine(t_philo *philo, t_sem *sem);
#endif
