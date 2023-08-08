/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:31:05 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/08 14:10:28 by ebennix          ###   ########.fr       */
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

long long	get_time(long long start_time)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		exit_msg("failed to get time of day.", RED, 2);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - start_time);
}

void	livelihood(t_data *var)
{
	unsigned int i;

	i = 0;
	while(1)
	{
		usleep(600);
		if (get_time(var->philos[i].last_meal) > var->death_t)
		{
			pthread_mutex_lock(&var->print);
			printf("-> %llu ms philo %d died.\n", get_time(var->start_clock),var->philos[i].id);
			break;
		}
		i++;
		if (i == var->n_philos)
			i = 0;
	}
}