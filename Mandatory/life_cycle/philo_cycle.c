/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:35:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/31 04:56:37 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long get_time(long start_time)
{
    struct timeval time;
    unsigned long s;
    unsigned long m;
    gettimeofday(&time, NULL);
    
    s = time.tv_sec * 1000;
    m = time.tv_usec / 1000;
    return ((s+m) - start_time);
}

// void dinner_time(t_list *philo , unsigned int time)
// {
//     pthread_mutex_lock(&philo->fork);
//     printf("%d ms philo = %d has taken a fork", );
//     pthread_mutex_lock(&philo->next->fork);
//     printf("%d ms philo = %d has taken a fork", );
//     printf("%d ms philo = %d is eating");
//     sleep(time);
//     //get time 
//     // incremet ate
//     pthread_mutex_unlock(&philo->fork);
//     pthread_mutex_unlock(&philo->next->fork);
// }

void    philo_cycle(t_data *var)
{
    (void)var;
    struct timeval time;
    gettimeofday(&time, NULL);

    sleep(5);
    printf("philo started = %lu \n", get_time((time.tv_sec*1000)+(time.tv_usec/1000)));
    sleep(5);
    printf("philo finished\n");

    // while(true)
    // {
    //     dinner_time(var->philosophers, var->eating_time);
    //     printf("%d ms philo = %d is sleeping");
    //     sleep(var->sleeping_time);
    //     printf("%d ms philo = %d is thinking");
    // }
}