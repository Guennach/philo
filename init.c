/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:45:39 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/31 19:35:20 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_init(char **av, t_philo *ph,
	int id, pthread_mutex_t *mt)
{
	ph[id].id = id;
	ph[id].checker = 0;
	if (av[5])
		ph[id].eating_counter = ft_atoi(av[5]);
	ph[id].time_to_die = ft_atoi(av[2]);
	ph[id].time_to_eat = ft_atoi(av[3]);
	ph[id].time_to_sleep = ft_atoi(av[4]);
	ph[id].eating_counter = 0;
	ph[id].lf = (id);
	ph[id].rf = ((id + 1) % (ft_atoi(av[1])));
	ph[id].last_meal_time = getcurrenttime(ph->tinf);
	ph[id].forks = mt;
	if (av[5])
		ph[id].eating_c = ft_atoi(av[5]);
	else 
		ph[id].eating_c = -1;
}

void	init_vars_main(t_vars *var)
{
	init_variables(&var->ph, &var->mt, &var->time_philo, &var->i);
	init_vars(&var->thread, &var->mtxa, &var->nbr_ph);
}

pthread_mutex_t	*forks_init(int nbr_philo)
{
	int				i;
	pthread_mutex_t	*mt;

	i = -1;
	mt = malloc(sizeof(pthread_mutex_t) * nbr_philo);
	while (++i < nbr_philo)
	{
		pthread_mutex_init(&(mt[i]), NULL);
	}
	return (mt);
}
