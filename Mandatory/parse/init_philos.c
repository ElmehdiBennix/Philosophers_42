/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:17:20 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/21 18:29:13 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

void init_philos(t_data *var)
{
    int i;
    t_philo *philos;

    i = 0;
    var->philosophers = malloc(var->numb_of_philos*sizeof(t_philo));
    if (!var->philosophers)
        exit_msg("Memory problem !!", RED, 2);
    philos = var->philosophers;
    while (philos)
    {
        philos->id = i;
        pthread_create(&philos->philo, NULL, NULL, NULL);
        
    }



}
