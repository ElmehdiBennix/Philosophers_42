/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:35:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/13 01:06:11 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static void	print_msg(t_philo *philo, char *action)
{
	sem_wait(philo->var->print);
	printf("-> %lu ms philo %d %s.\n", get_time(0)-philo->var->start_clock,
			philo->id, action);
	sem_post(philo->var->print);
}

static void	lock_fork(t_philo *philo)
{
	sem_wait(philo->var->fork);
	print_msg(philo, take);
	sem_wait(philo->var->fork);
	print_msg(philo, take);
}

static void	unlock_fork(t_philo *philo)
{
	sem_post(philo->var->fork);
	sem_post(philo->var->fork);
}

void	philo_cycle(t_philo *philo)
{
	pthread_t	monitor_th;

	if (philo->id % 2 == 0)
		usleep(250);
	pthread_create(&monitor_th ,NULL,(void *)livelihood,philo);
	philo->last_meal = get_time(0);
	while(1)
	{
		lock_fork(philo);
		print_msg(philo, eat);
		philo->last_meal = get_time(0);
		ft_usleep(philo->var->eating_t);
		if (philo->var->eating_reps != -1)
			philo->meals_n++;
		unlock_fork(philo);
		if (philo->var->eating_reps == philo->meals_n)
		{
			sem_post(philo->var->satisfied);
			exit(0);
		}
		print_msg(philo, sleepe);
		ft_usleep(philo->var->sleeping_t);
		print_msg(philo, think);
	}
}
//➜  philo_bonus git:(main) ✗ ./philo 1 310 200 100
