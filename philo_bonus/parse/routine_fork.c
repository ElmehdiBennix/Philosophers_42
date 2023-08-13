/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 01:15:41 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/13 01:28:00 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static	void    kill_child(pid_t *pid, t_data *var)
{
	int	i;

	i = -1;
	while (++i < var->n_philos)
		kill(pid[i], SIGTERM);
}

static  void    eating_reps_true(t_data *var)
{
	int i;

	i = -1;
	if (var->eating_reps != -1)
	{
		while (++i < var->n_philos)
		{
			usleep(50);
			sem_wait(var->satisfied);
		}
		sem_post(var->death);
	}
}

void	routine_fork(t_data *var)
{
	int		i;
	pid_t	p;

    p = 1;
	i = -1;
	pid_t *pid = malloc(sizeof(pid_t) * var->n_philos);
	if (!pid)
		return ;
	while (++i < var->n_philos && p != 0)
	{
		p = fork();
		if (p < 0)
			break;
		if (p == 0)
			philo_cycle(&var->philos[i]);
		pid[i] = p;
	}
	eating_reps_true(var);
	sem_wait(var->death);
	kill_child(pid, var);
	free(pid);
}