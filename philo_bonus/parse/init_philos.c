/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:17:20 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/12 04:05:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

sem_t	*open_semaphore(char *name, int sem_value)
{
	sem_t	*sema;

	sem_unlink(name);
	sema = sem_open(name, O_CREAT, 0660, sem_value);
	if (sema == SEM_FAILED)
		exit(1);//error msg
	return (sema);
}

void	kill_child(pid_t *pid, t_data *var)
{
	int	i;

	i = -1;
	while (++i < var->n_philos)
		kill(pid[i], SIGTERM);
}

int		fork_philos(t_data *var)
{
	int		i;
	pid_t	p;

	i = -1;
	pid_t *pid = malloc(sizeof(pid_t) * var->n_philos);
	if(!pid)
		exit(1);//msg
	while (++i < var->n_philos && p != 0)
	{
		p = fork();
		if (p < 0)
			break;
		if (p == 0)
			philo_cycle(&var->philos[i]);
		pid[i] = p;
	}
	i = 0;
	if (var->eating_reps != -1)
	{
		while (i < var->eating_reps)
		{
			sem_wait(var->meals_n);
			printf("%d\n",i);
			i++;
		}
		sem_post(var->death);
	}
	sem_wait(var->death); // if
	kill_child(pid,var);
	free(pid);
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
	var->death = open_semaphore("death", 0);
	if(var->eating_reps != -1)
		var->meals_n = open_semaphore("meals_n",0);
	var->print = open_semaphore("print", 1);
	while (++i < var->n_philos)
	{
		var->philos[i].id = i + 1;
		var->philos[i].var = var;
		var->philos[i].meals_n = 0;
		var->philos[i].last_meal = 0;
	}
	fork_philos(var);
	return (0);
}
