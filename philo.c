/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:47:21 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/14 21:25:06 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	main(int ac, char **av)
{
	int				i;
	t_philo			*ph;
	t_philo			*next_ph;
	pthread_t		*thread;
	int				nbr_ph;
	pthread_mutex_t	*mt;

	nbr_ph = 0;
	i = 0;
	ph = NULL;
	thread = NULL;
	mt = NULL;
	pthread_mutex_init(&mtx, NULL);
	pthread_mutex_init(&sl, NULL);
	if (ac == 5)
	{
		nbr_ph = ft_atoi(av[1]);
		mt = forks_init(nbr_ph);
		while (i < nbr_ph)
		{
			if (i == 0)
			{
				ph = ft_lstnew(i + 1);
				ph->forks = mt;
				philosopher_init(av, ph, i + 1);
				
			}
			else
			{
				next_ph = ft_lstnew(i + 1);
				next_ph->forks = mt;
				ft_lstadd_back(&ph, next_ph);
				philosopher_init(av, next_ph, i + 1);
			}
			i++;
		}
		
		thread = create_threads(nbr_ph, ph, mt);
		

	}
	forks_destroyer(mt, nbr_ph);
	return (0);
}
