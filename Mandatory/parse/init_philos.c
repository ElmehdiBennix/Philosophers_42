/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:17:20 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/26 19:26:43 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

void init_philos(t_data *var)
{
    int     i;
    void    *p;
    t_list  *tmp;

    i = 0;
    while (i <= var->numb_of_philos)
    {
        p = malloc(sizeof(t_philo));
        if (!p)
            exit_msg("Memory problem !!", RED, 1);
        if (i == 0)
            var->philosophers = ft_lstnew(p);
        else
	        ft_lstcreate_back(&var->philosophers,p);
        i++;
    }
	tmp = ft_lstlast(var->philosophers);
	tmp->next = var->philosophers;
}
