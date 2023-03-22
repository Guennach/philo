/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:00:28 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/22 17:42:09 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct	v_time
{
	int	time_to_eat;
	int	time_to_die;
	int	time_to_sleep;
	long long		birth;
}			t_time;

typedef	struct	v_info
{
	struct	timeval first;
	long			start;
}				t_info;

typedef struct v_lock
{
	pthread_mutex_t	mtx;
}				t_lock;

typedef	struct v_philo
{
	int				id;
	int				lf;
	int				checker;
	int				eating_counter;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*forks;
	long long		start_time;
	long long		last_meal_time;
	t_info			*tinf;
	t_lock			*lock;
	pthread_mutex_t	*mtxa;
	int				rf;
	int				check;
	int				*point;
	void			*next;
}				t_philo;

pthread_mutex_t	mot;

// Args checker
int				ft_atoi(char *str);

// Init (create lists)
void			ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo			*ft_lstnew(int	id);
t_philo			*ft_lstlast(t_philo *lst);
void			ft_lstadd_front(t_philo **lst, t_philo *new);
// Routines
void			*routine(void *data);

// Init variables
void			philosopher_init(char **av, t_philo *ph, int id, pthread_mutex_t *mt);

// threads and mutex init
void			create_threads(int nbr_ph, t_philo *ph, pthread_t *thread);
pthread_mutex_t	*forks_init(int nbr_philo);
void			forks_destroyer(pthread_mutex_t *mt, int nbr_philo);

int				check_death(t_philo *ph);

// time
long long 		getcurrenttime(t_info *tv);
void			ft_usleep(long long time_to_do, t_info *tf);

#endif