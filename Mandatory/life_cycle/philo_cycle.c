/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:35:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/08 14:34:30 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	print_msg(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->var->print);
	printf("-> %llu ms philo %d %s.\n", get_time(philo->var->start_clock),
			philo->id, action);
	pthread_mutex_unlock(&philo->var->print);
	return (0);
}

static int	lock_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->l_fork));
	print_msg(philo, take);
	pthread_mutex_lock(philo->r_fork);
	print_msg(philo, take);
	return (0);
}
static int	unlock_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->l_fork));
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

void	*philo_cycle(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(250);
	philo->last_meal = get_time(0);
	while (1)
	{
		lock_fork(philo);
		print_msg(philo, eat);
		philo->last_meal = get_time(0);
		ft_usleep(philo->var->eating_t);
		if (philo->var->eating_reps != -1)
			philo->meals_n++;
		unlock_fork(philo);
		if (philo->var->eating_reps == philo->meals_n)
			philo->var->satisfied++;
		print_msg(philo, sleepe);
		ft_usleep(philo->var->sleeping_t);
		print_msg(philo, think);
	}
}
