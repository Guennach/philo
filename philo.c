/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:47:21 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/27 21:53:33 by gothmane         ###   ########.fr       */
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

	mine = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mine, NULL);
	init_vars_main(&var);
	if (ac == 5 || ac == 6)
	{	
		if (check_args(av, ac) == 1)
			return (1);
		var.nbr_ph = ft_atoi(av[1]);
		init_philo_memory(&var.ph, &var.mt, var.mtxa, &var.nbr_ph);
		philos_main_init(var, mine, av);
		create_threads(var.nbr_ph, var.ph, var.thread);
		if (checker_philo(var.ph, av) == 0)
			return (1);
	}
	// forks_destroyer(var.mt, var.nbr_ph, mine);
	// frees_wrapper(var.ph, var.thread, var.mt, mine);
	return (0);
}
