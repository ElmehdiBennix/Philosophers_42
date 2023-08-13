/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:31:05 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/13 01:36:13 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_usleep(unsigned long time_in_ms)
{
	long	start_time;

	start_time = get_time(0);
	while (get_time(start_time) < time_in_ms)
		usleep(100);
}

unsigned long	get_time(unsigned long start_time)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		exit_msg("failed to get time of day.", RED, 2);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - start_time);
}

void	livelihood(t_philo *philo)
{
	while(TRUE)
	{
		usleep(500);
		if (get_time(philo->last_meal) > philo->var->death_t)
		{
			sem_wait(philo->var->print);
			printf("-> %lu ms philo %d died.\n", get_time(philo->var->start_clock),philo->id);
			if (philo->var->eating_reps == -1)
				sem_post(philo->var->death);
			while (philo->meals_n != philo->var->eating_reps && philo->var->eating_reps != -1)
				sem_post(philo->var->satisfied);
		}
	}
}

