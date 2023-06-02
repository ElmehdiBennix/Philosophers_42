/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:35:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/02 15:59:01 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// void dinner_time(t_list *philo , long time)
// {
//     pthread_mutex_lock(&philo->fork);
//     pthread_mutex_lock(&philo->next->fork);
//     printf("%lu ms philo = %d has taken a fork\n",get_time(time), philo->id);
//     printf("%lu ms philo = %d has taken a fork\n",get_time(time), philo->id);
//     printf("%lu ms philo = %d is eating\n", get_time(time), philo->id);
//     usleep(philo->var->eating_time);
//     philo->last_eat = get_time(time);
//     philo->n_eat++;
//     pthread_mutex_unlock(&philo->fork);
//     pthread_mutex_unlock(&philo->next->fork);
// }

void    philo_cycle(t_philo *philo)
{
    // unsigned long time = get_time(0);

    printf("philo id = %d\n",philo->id);
    // sleep(5);
    // printf("philo started = %lu \n", get_time(bruh));
    // sleep(5);
    // printf("philo started = %lu \n", get_time(bruh));
    // printf("philo finished\n");

    // while(true)
    // {
    //     dinner_time(philo, time);
    //     printf("%lu ms philo = %d is sleeping\n",get_time(time), philo->id);
    //     usleep(philo->var->sleeping_time);
    //     printf("%lu ms philo = %d is thinking\n",get_time(time), philo->id);
    // }
}

// make file problem