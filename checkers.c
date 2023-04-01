/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:44:59 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/27 17:57:42 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	nbr_eating(t_philo *ph, char **av, int i, int *checker_eat)
{
	int	theres_time_eat;

	theres_time_eat = 1;
	if (*checker_eat <= ft_atoi(av[1]))
	{
		if (ph[i].eating_counter == ft_atoi(av[5]) + 1)
			*checker_eat = *checker_eat + 1;
		if (*checker_eat == ft_atoi(av[1]) && theres_time_eat == 1)
			return (0);
	}
	return (1);
}

int	death_checker(t_philo *ph, int *a, int *c, int i)
{
	long	check;

	check = getcurrenttime(ph->tinf) - ph[i].last_meal_time;
	if (check > ph[i].time_to_die)
	{
		*a = 1;
		*c = 1;
		pthread_mutex_lock(ph->mtxa);
		usleep(500);
		printf("%lld %d died\n", getcurrenttime(ph->tinf)
			- ph[i].start_time, ph[i].id);
		pthread_mutex_unlock(ph->mtxa);
		return (0);
	}
	return (1);
}

void	var_init_checkers(int *checker_eat, int *a, int *i, int *c)
{
	*checker_eat = 0;
	*a = 0;
	*c = 0;
	*i = 0;
}

int	checker_philo(t_philo *ph, char **av)
{
	int	a;
	int	checker_eat;
	int	i;

	var_init_checkers(&checker_eat, &a, &i, &ph->check);
	while (a == 0)
	{
		i = -1;
		while (++i < ft_atoi(av[1]))
		{
			if (ph[i].last_meal_time > 0
				&& death_checker(ph, &a, &ph->check, i) == 0)
				return (0);
			if (av[5] && nbr_eating(ph, av, i, &checker_eat) == 0)
				return (0);
		}
	}
	return (1);
}
