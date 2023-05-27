/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:17:20 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/27 19:18:06 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

void init_philos(t_data *var)
{
    t_list  *tmp;
    unsigned int    i;

    i = 1;
    while (i < var->numb_of_philos + 1)
    {
        if (i == 1)
            var->philosophers = ft_lstnew(i);
        else
	        ft_lstcreate_back(&var->philosophers,i);
        i++;
    }
	tmp = ft_lstlast(var->philosophers);
	tmp->next = var->philosophers;
}
