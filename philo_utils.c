/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:55:29 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/14 19:07:25 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
	int res;
	int sign;
	int i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

pthread_t *create_threads(int nbr_ph, t_philo *ph, pthread_mutex_t *mt)
{
	int i;
	pthread_t *thread;

	i = 0;
	thread = malloc(sizeof(pthread_t) * nbr_ph);
	if (!thread)
		return (0);
	while (i < nbr_ph)
	{
		ph->left_fork = mt[i];
		ph->right_fork = mt[(i + 1) % nbr_ph];
		if (pthread_create(&thread[i], NULL, &routine, (void *)ph))
			return (0);
		if (ph->next)
			ph = ph->next;
		i++;
	}
	i = -1;
	while (++i < nbr_ph)
	{	
		if (pthread_join(thread[i], NULL))
			return (0);
	}
	return (thread);
}
