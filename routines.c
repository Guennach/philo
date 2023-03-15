/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:45:28 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/15 15:56:04 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo			*ph;
	t_philo			*head;
	// int				early_time_to_die;
	long			cur_time;
	t_info			*time_philo;

	cur_time = 0;
	ph = (t_philo *)data;
	head = ph;
	time_philo = malloc(sizeof(t_info));
	if (!time_philo)
		return (0);
	if (!time_philo->start)
		time_philo->start = getcurrenttime(time_philo);
	if (!cur_time)
		cur_time = time_philo->start;
	
	while (1)
	{
		
		
		// pthread_mutex_lock(&mtx);
		// cur_time = getcurrenttime(time_philo);
		// printf("%ld %d is thinking\n", (cur_time - time_philo->start) , ph->id);
		// usleep(100);
		
		// pthread_mutex_unlock(&mtx);
		

		// pthread_mutex_lock(&(ph->forks[ph->lf]));
		// cur_time = getcurrenttime(time_philo);
		// printf("%ld %d has taken a fork\n", (cur_time - time_philo->start) , ph->id);

		// pthread_mutex_lock(&(ph->forks[ph->rf]));
		// cur_time = getcurrenttime(time_philo);
		// printf("%ld %d has taken a fork\n", (cur_time - time_philo->start) , ph->id);

		// cur_time = getcurrenttime(time_philo);
		// printf("%ld %d is eating\n", (cur_time - time_philo->start) , ph->id);
		// usleep((ph->time_to_eat * 1000));
		// pthread_mutex_unlock(&(ph->forks[ph->lf]));
		// pthread_mutex_unlock(&(ph->forks[ph->rf]));


		// pthread_mutex_lock(&sl);pthread_mutex_unlock(&sl);
		
		cur_time = getcurrenttime(time_philo);
		printf("%ld %d is sleeping\n", (cur_time - time_philo->start) , ph->id);
		
		while ((getcurrenttime(time_philo) - cur_time) <= (ph->time_to_sleep * 1000))
			usleep(ph->time_to_sleep * 1000);
		
	}
	return(0);
}
