/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:47:21 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/22 18:19:54 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	int i;
	t_philo *ph;
	// t_philo			*next_ph;
	pthread_t *thread;
	int nbr_ph;
	pthread_mutex_t *mt;
	t_lock *lock;
	t_info *time_philo;
	pthread_mutex_t *mtxa;

	nbr_ph = 0;
	i = 0;
	ph = NULL;
	thread = malloc(sizeof(pthread_t) * nbr_ph);
	mt = NULL;
	lock = malloc(sizeof(t_lock));
	time_philo = malloc(sizeof(t_info));
	mtxa = malloc(sizeof(pthread_mutex_t));

	pthread_mutex_init(mtxa, NULL);
	pthread_mutex_init(&mot, NULL);
	pthread_mutex_init(&(lock->mtx), NULL);
	if (ac == 5)
	{
		nbr_ph = ft_atoi(av[1]);
		mt = forks_init(nbr_ph);
		ph = malloc(sizeof(t_philo) * nbr_ph);
		while (i < nbr_ph)
		{
			ph[i].tinf = time_philo;
			ph[i].start_time = getcurrenttime(time_philo);
			ph[i].mtxa = mtxa;
			ph[i].lock = lock;
			ph[i].check = 0;
			ph[i].point = &ph->check;
			philosopher_init(av, ph, i + 1, mt);
			i++;
		}
		create_threads(nbr_ph, ph, thread);
		// int a = 0;

		// while (a == 0)
		// {
		// 	i = -1;
		// 	while (++i < nbr_ph)
		// 	{
		// 		if (ph[i].last_meal_time > 0)
		// 		{
		// 			long check = getcurrenttime(time_philo) - ph[i].last_meal_time;
		// 			if (check > ph[i].time_to_die)
		// 			{
		// 				a = 1;
		// 				ph[i].check = 1;
		// 				// printf("HADI 2 = >>>>>>>>>>>>>>>> CHECK VALUE = %d <<<<<<<<<<<<<<<<<<\n", ph->check);
		// 				printf("%lld %d died\n", getcurrenttime(time_philo) - ph[i].start_time, ph[i].id);
		// 				// exit(0);
		// 			}
		// 		}
		// 	}
		// }

		i = -1;
		while (++i < nbr_ph)
		{
			if (pthread_join(thread[i], NULL))
				return (0);
		}
	}
	forks_destroyer(mt, nbr_ph);
	return (0);
}
