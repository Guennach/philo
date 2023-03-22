/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:53:15 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/21 15:08:01 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long getcurrenttime(t_info *tv)
{
	
	long long		time;
	
    gettimeofday(&tv->first, NULL);
	time = ((tv->first.tv_sec * 1000) + (tv->first.tv_usec / 1000));
	return (time);
}

void	ft_usleep(long long time_to_do, t_info *tf)
{
	long long ct;
	long long tmp;

	ct = getcurrenttime(tf);
	tmp = getcurrenttime(tf);
	while ((tmp - ct) < time_to_do)
	{
		usleep(1000);
		tmp = getcurrenttime(tf);
	}
}
