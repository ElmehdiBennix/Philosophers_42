/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:35:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/30 05:35:05 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// void get_time()
// {
    
// }

void dinner_time(t_list *philo , unsigned int time)
{
    pthread_mutex_lock(&philo->fork);
    pthread_mutex_lock(&philo->next->fork);
    printf("philo is eating");
    sleep(time);
    //get time 
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(&philo->next->fork);
}

void    philo_cycle(t_data *var)
{
    while(true)
    {
        dinner_time(var->philosophers, var->eating_time);
        printf("philo is sleeping");
        sleep(var->sleeping_time);
        printf("philo is thinking");
    }
}