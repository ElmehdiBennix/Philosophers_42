/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:35:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/07/28 06:17:08 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    dinner_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->l_fork);
    pthread_mutex_lock(&(*philo->r_fork));
    printf("%llu ms philo = %d has taken a fork\n",get_time(philo->var->start_clock), philo->id);
    printf("%llu ms philo = %d has taken a fork\n",get_time(philo->var->start_clock), philo->id);
    printf("%llu ms philo = %d is eating\n", get_time(philo->var->start_clock), philo->id);
    usleep(philo->var->eating_t);
    philo->last_meal = get_time(philo->var->start_clock);
    if (philo->var->eating_reps != -1)
        philo->meals_n++;
    pthread_mutex_unlock(&philo->l_fork);
    pthread_mutex_unlock(&(*philo->r_fork));
}

int    livelihood(t_philo *philo)
{
    if (get_time(philo->last_meal) > philo->var->death_t)
    {
        printf("%llu ms philo = %d has died\n",get_time(philo->var->start_clock), philo->id);
        return true;
    }
    return FALSE ;
}

void    *philo_cycle(t_philo *philo)
{
    
    if (philo->id / 2 == 0)
        usleep(10);
    while(livelihood(philo) == TRUE) // is alive
    {
        dinner_time(philo);
        printf("%llu ms philo = %d is sleeping\n",get_time(philo->var->start_clock), philo->id);
        usleep(philo->var->sleeping_t);
        printf("%llu ms philo = %d is thinking\n",get_time(philo->var->start_clock), philo->id);   
    }
}

// make file problem