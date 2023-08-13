/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:17:20 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/13 01:29:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static	sem_t	*open_semaphore(char *name, int sem_value)
{
	sem_t	*sema;

	sem_unlink(name);
	sema = sem_open(name, O_CREAT, 0660, sem_value);
	if (sema == SEM_FAILED)
	{
		exit_msg("semaphore failed.",YELLOW,4);
		exit(4);
	}
	return (sema);
}

int	init_var(t_data *var)
{
	int	i;

	i = -1;
	var->start_clock = get_time(0);
	var->philos = malloc(sizeof(t_philo) * var->n_philos);
	if (!var->philos)
		return (2);
	var->fork = open_semaphore("fork",var->n_philos);
	var->print = open_semaphore("print", 1);
	var->death = open_semaphore("death", 0);
	if (var->eating_reps != -1)
		var->satisfied = open_semaphore("satisfied",0);
	while (++i < var->n_philos)
	{
		var->philos[i].id = i + 1;
		var->philos[i].var = var;
		var->philos[i].meals_n = 0;
		var->philos[i].last_meal = 0;
	}
	return (0);
}
