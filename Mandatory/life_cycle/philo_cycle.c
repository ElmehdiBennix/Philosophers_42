/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:35:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/04 03:03:53 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_usleep(long time_in_ms)
{
	long	start_time;

	start_time = get_time(0);
	while (get_time(start_time) < time_in_ms)
		usleep(100);
}

int    livelihood(t_philo *philo) // t_data *var
{
    printf("id = %d this is the last meal %lld > death time %d\n" ,philo->id,get_time(philo->last_meal) , philo->var->death_t );
    if (get_time(philo->last_meal) > philo->var->death_t)
    {
		pthread_mutex_lock(&philo->var->print);
        printf("%llu ms philo = %d has died\n",get_time(philo->var->start_clock), philo->id);
		pthread_mutex_lock(&philo->var->death);
		philo->var->stop = TRUE;
        // pthread_mutex_unlock(&philo->var->death);
        return (philo->var->stop);
        // return TRUE; //stop sim once death
    }
    return (philo->var->stop);

	//free data and loop over all philos 
}

int     lock_fork(t_philo *philo)
{
    pthread_mutex_lock(&(philo->l_fork));
    pthread_mutex_lock(philo->r_fork);
    return (0);
}
int     unlock_fork(t_philo *philo)
{
    pthread_mutex_unlock(&(philo->l_fork));
    pthread_mutex_unlock(philo->r_fork);
    return (0);
}

# define take "has taken a fork"
# define eat "is eating"
# define sleep "is sleeping"
# define think "is thinking"

int     print_msg(t_philo *philo , char *action)
{
    pthread_mutex_lock(&(philo->var->print)); // problems dead lock for some reason
    printf("%llu ms philo = %d %s\n",get_time(philo->var->start_clock), philo->id ,action);
    pthread_mutex_unlock(&(philo->var->print));
    return (0);
}


void    *philo_cycle(t_philo *philo)
{
    philo->last_meal = get_time(0);
    if (philo->id % 2 == 0)
        ft_usleep(50);
    while(1)
    {
        lock_fork(philo);
        print_msg(philo,take);
        print_msg(philo,take);
        print_msg(philo,eat);
        ft_usleep(philo->var->eating_t);
        philo->last_meal = get_time(0);
        if (philo->var->eating_reps != -1)
            philo->meals_n++;
        unlock_fork(philo);
        print_msg(philo,sleep);
        ft_usleep(philo->var->sleeping_t);
        print_msg(philo,think);
        livelihood(philo);
    }
}

// make file problem