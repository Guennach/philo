/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:45:39 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/14 19:22:24 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_init(char **av, t_philo *ph, int id)
{	
	ph->id = id;
	ph->checker = 0;
	if (av[5])
		ph->eating_counter = ft_atoi(av[5]);
	ph->time_to_die = ft_atoi(av[2]);
	ph->time_to_eat = ft_atoi(av[3]);
	ph->time_to_sleep = ft_atoi(av[4]);
	ph->eating_counter = -1;
	ph->lf = id - 1;
	ph->rf = id % ft_atoi(av[1]);
	// ph->forks = mt;
}

// void	data_visualiser(t_philo *ph)
// {
// 	while(ph)
// 	{
// 		printf("Philo id = %d\n", ph->id);
// 		ph = ph->next;
// 	}
// }	

pthread_mutex_t	*forks_init(int nbr_philo)
{
	int				i;
	pthread_mutex_t	*mt;

	i = 0;
	mt = malloc(sizeof(pthread_mutex_t) * nbr_philo);
	while (i < nbr_philo)
	{
		pthread_mutex_init(&(mt[i]), NULL);
		i++;
	}
	return (mt);
}

void	forks_destroyer(pthread_mutex_t *mt, int nbr_philo)
{
	int				i;

	i = 0;
	while (i < nbr_philo)
	{
		pthread_mutex_destroy(&(mt[i]));
		i++;
	}
}
