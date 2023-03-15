/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:45:14 by gothmane          #+#    #+#             */
/*   Updated: 2023/03/13 20:11:33 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_philo	*ft_lstnew(int	id)
{
	t_philo	*ls;

	ls = malloc(sizeof(t_philo));
	ls->id = id;
	ls->next = NULL;
	return (ls);
}

void	ft_lstadd_front(t_philo **lst, t_philo *new)
{
	// t_list *s;

	// s = ft_lstnew(new->content);
	new->next = *lst;
	*lst = new;
}



t_philo	*ft_lstlast(t_philo *lst)
{
	t_philo	*current;

	current = lst;
	if (!lst)
		return (NULL);
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}
