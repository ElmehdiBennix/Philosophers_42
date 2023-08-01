/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:35:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/01 15:24:19 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void    dinner_time(t_philo *philo)
{
    pthread_mutex_lock(&(philo->l_fork));
    pthread_mutex_lock(philo->r_fork);
    pthread_mutex_lock(&philo->var->print);
    printf("%llu ms philo = %d has taken a fork\n",get_time(philo->var->start_clock), philo->id);
    printf("%llu ms philo = %d has taken a fork\n",get_time(philo->var->start_clock), philo->id);
    printf("%llu ms philo = %d is eating\n", get_time(philo->var->start_clock), philo->id);
    pthread_mutex_unlock(&philo->var->print);
    philo->last_meal = get_time(0);
    usleep(philo->var->eating_t * 1000);
    if (philo->var->eating_reps != -1)
        philo->meals_n++;
    pthread_mutex_unlock(&(philo->l_fork));
    pthread_mutex_unlock(philo->r_fork);
}

void    *philo_cycle(t_philo *philo)
{
    if (philo->id % 2 == 0)
        usleep(50);
    while(1)
    {
        dinner_time(philo);
        pthread_mutex_lock(&philo->var->print);
        printf("%llu ms philo = %d is sleeping\n", get_time(philo->var->start_clock), philo->id);
        pthread_mutex_unlock(&philo->var->print);
        usleep(philo->var->sleeping_t * 1000);
        pthread_mutex_lock(&philo->var->print);
        printf("%llu ms philo = %d is thinking\n",get_time(philo->var->start_clock), philo->id);
        pthread_mutex_unlock(&philo->var->print);
    }
}

// make file problem