/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:45:28 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/22 18:19:31 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void dec_time_die(t_philo *ph, t_info *ta, int state, long long lmt)
{
	t_philo *cph;
	long formula;

	formula = 0;
	cph = ph;
	if (state == 1)
		formula = (ph->time_to_die) - (getcurrenttime(ta) - lmt);
	else if (state == 0)
		formula = ph->time_to_die;
	if (formula <= 0)
	{
		printf("%lld %d has died\n", getcurrenttime(ta) - ph->start_time, ph->id);
		exit(0);
	}
}

int check_death(t_philo *ph)
{
	// long	formula;

	// if (ph->last_meal_time == 0)
	// 	return (1);
	// formula = getcurrenttime(ph->tinf) - ph->last_meal_time;
	// if (formula > ph->time_to_die)
	// {
	// 	pthread_mutex_lock(&(mot));
	// 	printf("%lld %d has died\n", (getcurrenttime(ph->tinf) - ph->start_time), ph->id);
	// 	// pthread_mutex_unlock((ph->mtxa));
	// 	return (0);
	// }

	printf(">>>>>>>>> PHILO %d || LAST TIME TO EAT = %lld <<<<<<<<<\n", ph->id, (getcurrenttime(ph->tinf) - ph->last_meal_time));
	return (1);
}

void show_msg(t_philo *ph)
{
	// if (*ph->point == 1)
	// 		return ;
	pthread_mutex_lock((ph->mtxa));
	printf("%lld %d is thinking\n", (getcurrenttime(ph->tinf) - ph->start_time), ph->id);
	pthread_mutex_unlock((ph->mtxa));
	pthread_mutex_lock(&(ph->forks[ph->lf]));
	pthread_mutex_lock(&(ph->forks[ph->rf]));
	pthread_mutex_lock((ph->mtxa));
	printf("%lld %d has taken a fork\n", (getcurrenttime(ph->tinf) - ph->start_time), ph->id);
	pthread_mutex_unlock((ph->mtxa));
	pthread_mutex_lock((ph->mtxa));
	printf("%lld %d has taken a fork\n", (getcurrenttime(ph->tinf) - ph->start_time), ph->id);
	pthread_mutex_unlock((ph->mtxa));
	pthread_mutex_lock((ph->mtxa));
	// printf(">>>>>>>>>>>>> PHILO %d || NEW TIME = %lld <<<<<<<<<<\n", ph->id, ph->last_meal_time);
	printf("%lld %d is eating\n", (getcurrenttime(ph->tinf) - ph->start_time), ph->id);
	ph->last_meal_time = getcurrenttime(ph->tinf);
	pthread_mutex_unlock((ph->mtxa));

	ph->eating_counter++;
	ft_usleep(ph->time_to_eat, ph->tinf);
	pthread_mutex_unlock(&(ph->forks[ph->lf]));
	pthread_mutex_unlock(&(ph->forks[ph->rf]));
	pthread_mutex_lock((ph->mtxa));
	printf("%lld %d is sleeping\n", (getcurrenttime(ph->tinf) - ph->start_time), ph->id);
	pthread_mutex_unlock((ph->mtxa));
	ft_usleep(ph->time_to_sleep, ph->tinf);
}

void *routine(void *data)
{
	t_philo *ph;

	ph = (t_philo *)data;
	while (1)
	{
		show_msg(ph);
	}
	return (0);
}
