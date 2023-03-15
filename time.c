/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:53:15 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/13 17:49:09 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	getcurrenttime(t_info *tv)
{
	
	long		time;
	
    gettimeofday(&tv->first, NULL);
	time = ((tv->first.tv_sec * 1000) + (tv->first.tv_usec / 1000));
	return (time);
}

