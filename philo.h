/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:00:28 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/14 21:24:53 by gothmane         ###   ########.fr       */
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
}			t_time;

typedef	struct v_philo
{
	int				id;
	int				checker;
	int				eating_counter;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*forks;
	int				lf;
	int				rf;
	void			*next;
}				t_philo;

typedef	struct	v_info
{
	struct	timeval first;
	long			start;
}				t_info;

pthread_mutex_t	mtx;
pthread_mutex_t	sl;
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
void			philosopher_init(char **av, t_philo *ph, int nbr_ph);
pthread_t		*create_threads(int nbr_ph, t_philo *ph, pthread_mutex_t *mt);
pthread_mutex_t	*forks_init(int nbr_philo);
void			forks_destroyer(pthread_mutex_t *mt, int nbr_philo);
long			getcurrenttime(t_info *tv);


// needs
void			data_visualiser(t_philo *ph);


#endif