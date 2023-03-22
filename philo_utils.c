/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:55:29 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/22 17:01:32 by gothmane         ###   ########.fr       */
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

void create_threads(int nbr_ph, t_philo *ph, pthread_t *thread)
{
	int i, check;

	i = -1;
	check = 0;
	if (!thread)
		return;
	while (++i < nbr_ph)
	{
		if (pthread_create(&thread[i], NULL, &routine, ((void *)&ph[i])))
			return;
		usleep(100);
	}

}
