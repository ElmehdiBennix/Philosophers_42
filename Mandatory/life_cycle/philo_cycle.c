/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:35:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/07 06:31:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	livelihood(t_philo *philo)
{
	printf("id = %d this is the last meal %lld > death time %d\n", philo->id,
			get_time(philo->last_meal), philo->var->death_t);
	if (get_time(philo->last_meal) > philo->var->death_t)
	{
		pthread_mutex_lock(&philo->print);
		printf("-> %llu ms philo %d died.\n", get_time(philo->var->start_clock),
				philo->id);
		pthread_mutex_lock(&philo->var->death); // no need for it i think
		philo->var->stop = TRUE;
		pthread_mutex_unlock(&philo->var->death);
	}
}

static int	print_msg(t_philo *philo, char *action)
{
	pthread_mutex_lock(&(philo->print));
	printf("-> %llu ms philo %d %s.\n", get_time(philo->var->start_clock),
			philo->id, action);
	pthread_mutex_unlock(&(philo->print));
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

void	philo_cycle(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(500);
	philo->last_meal = get_time(0);
	while (philo->var->stop == false)
	{
		lock_fork(philo);
		print_msg(philo, eat);
		philo->last_meal = get_time(0);
		ft_usleep(philo->var->eating_t);
		if (philo->var->eating_reps != -1)
			philo->meals_n++;
		unlock_fork(philo);
		if (philo->var->eating_reps == philo->meals_n)
			return ;
		print_msg(philo, sleep);
		ft_usleep(philo->var->sleeping_t);
		print_msg(philo, think);
		livelihood(philo);
	}
}

// make file problem