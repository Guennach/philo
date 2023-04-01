/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:47:21 by gothmane          #+#    #+#             */
/*   Updated: 2023/04/01 14:59:31 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char	**av, int ac)
{
	int	c;

	c = 0;
	while (++c < ac)
	{
		if (ft_atoi(av[c]) <= 0)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars			var;
	pthread_mutex_t	*mine;
	pthread_t		*th;
	pthread_mutex_t	*forks;

	mine = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mine, NULL);
	init_vars_main(&var);
	th = malloc(sizeof(th) * ft_atoi(av[1]));
	forks = NULL;
	if (ac == 5 || ac == 6)
	{
		if (check_args(av, ac) == 1
			&& (frees_wrapper(var.ph, var.thread, var.mt, mine) == 0)
			&& forks_destroyer(var.mt, var.nbr_ph, mine) == 1)
			return (1);
		var.nbr_ph = ft_atoi(av[1]);
		init_philo_memory(&var.ph,  &var.mtxa, &var.nbr_ph);
		forks = philos_main_init(var, mine, av);
		create_threads(var.nbr_ph, var.ph, th);
		if (checker_philo(var.ph, av) == 0)
		{
			if (!join_threads(var.nbr_ph, th))
				return (0);
			forks_destroyer(forks, var.nbr_ph, mine);
			frees_wrapper(var.ph, th, forks, mine);
			while(1);
			return (1);
		}
	}
	forks_destroyer(forks, var.nbr_ph, mine);
	frees_wrapper(var.ph, th, forks, mine);
	return (0);
}

