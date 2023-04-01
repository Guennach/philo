/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:45:28 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/31 19:17:48 by gothmane         ###   ########.fr       */
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

void	show_msg(t_philo *ph, int *tmp)
{
	type_msg(ph, "is thinking");
	pthread_mutex_lock(&(ph->forks[ph->lf]));
	type_msg(ph, "has taken a fork");
	pthread_mutex_lock(&(ph->forks[ph->rf]));
	type_msg(ph, "has taken a fork");
	type_msg(ph, "is eating");
	ph->last_meal_time = getcurrenttime(ph->tinf);
	// ph->eating_counter++;
	(*tmp)--;
	// printf("ph = %d || eating counter = %d\n", ph->id, ph->eating_counter);
	ft_usleep(ph->time_to_eat, ph->tinf, ph->point);
	pthread_mutex_unlock(&(ph->forks[ph->lf]));
	pthread_mutex_unlock(&(ph->forks[ph->rf]));
	type_msg(ph, "is sleeping");
	ft_usleep(ph->time_to_sleep, ph->tinf, ph->point);
}

void	*routine(void *data)
{
	t_philo	*ph;
	int		tmp;

	ph = (t_philo *)data;
	tmp = ph->eating_c;
	while (*ph->point == 0 && tmp)
		show_msg(ph, &tmp);
	ph->eating_c = tmp;
	return (NULL);
}
