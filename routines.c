/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:45:28 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/26 14:29:31 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	type_msg(t_philo *ph, char *s)
{
	pthread_mutex_lock(ph->mtxa);
	if (*ph->point == 0)
		printf("%lld %d %s\n", (getcurrenttime(ph->tinf)
				- ph->start_time), ph->id, s);
	pthread_mutex_unlock(ph->mtxa);
}

void	show_msg(t_philo *ph)
{
	int c,k = 0;
	type_msg(ph, "is thinking");
	c = pthread_mutex_lock(&(ph->forks[ph->lf]));
	type_msg(ph, "has taken a fork");
	printf("fork nbr = %p || c = %d\n", &ph->forks[ph->lf], c);
	k = pthread_mutex_lock(&(ph->forks[ph->rf]));
	type_msg(ph, "has taken a fork");
	printf("fork nbr = %p || k = %d\n", &ph->forks[ph->rf], k);
	type_msg(ph, "is eating");
	ph->last_meal_time = getcurrenttime(ph->tinf);
	ph->eating_counter++;
	ft_usleep(ph->time_to_eat, ph->tinf);
	pthread_mutex_unlock(&(ph->forks[ph->lf]));
	pthread_mutex_unlock(&(ph->forks[ph->rf]));
	type_msg(ph, "is sleeping");
	ft_usleep(ph->time_to_sleep, ph->tinf);
}

void	*routine(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	while (1)
	{
		show_msg(ph);
	}
	return (0);
}
