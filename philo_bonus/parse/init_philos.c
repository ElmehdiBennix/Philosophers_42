/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:17:20 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/10 15:30:03 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static	int init_philos(t_data *var)
{
	int	i;

	i = -1;
	while (++i < var->n_philos)
	{
		var->philos[i].id = i + 1;
		var->philos[i].var = var;
		var->philos[i].meals_n = 0;
		var->philos[i].r_fork = NULL;
		if (pthread_mutex_init(&var->philos[i].l_fork, NULL) != 0)
			return (2);
		if (i != var->n_philos - 1)
			var->philos[i].r_fork = &var->philos[i + 1].l_fork;
		else
			var->philos[i].r_fork = &var->philos[0].l_fork;
		if (pthread_create(&var->philos[i].p_thread, NULL, (void *)philo_cycle ,&var->philos[i]) != 0)
			return (2);
	}
	return (0);
}

int	init_var(t_data *var)
{
	int	i;

	i = -1;
	var->satisfied = 0;
	var->start_clock = get_time(0);
	if (pthread_mutex_init(&var->print, NULL) != 0)
		return (2);
	var->philos = malloc(sizeof(t_philo) * var->n_philos);
	if (!var->philos)
		return (2);
	if (init_philos(var) != 0)
		return (2);
	while (++i < var->n_philos)
		if (pthread_detach(var->philos[i].p_thread) != 0)
			return (2);
	livelihood(var);
	return (0);
}
