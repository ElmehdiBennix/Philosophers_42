/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:17:20 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/01 15:36:48 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

int    livelihood(t_philo *philo) // t_data *var
{
    if (get_time(0) - philo->last_meal >= philo->var->death_t)
    {
		pthread_lock(philo->var->print);
        printf("%llu ms philo = %d has died\n",get_time(philo->var->start_clock), philo->id);
        // return TRUE; //stop sim once death
		pthread_lock(philo->var->death);
		philo->var->stop = TRUE;
		pthread_unlock(philo->var->death);
    }
	//free data and loop over all philos 
}

int	init_philo(t_data *var)
{
	unsigned int i;
	
	var->start_clock = get_time(0);
	i = -1;
	var->philos = malloc(sizeof(t_philo) * var->n_philos);
	if (!var->philos)
		return (2);
	while(++i < var->n_philos)
	{
		var->philos[i].id = i;
		var->philos[i].var = var;
		var->philos[i].meals_n = 0;
		var->philos[i].last_meal = get_time(0);
		var->philos[i].r_fork = NULL;
		// stops var should be false
		if (pthread_mutex_init(&var->philos[i].l_fork, NULL) != 0)
			return (2);
		if (i != var->n_philos - 1)
			var->philos[i].r_fork = &var->philos[i + 1].l_fork;
		else
			var->philos[i].r_fork = &var->philos[0].l_fork;
		if (pthread_create(&var->philos[i].p_thread, NULL,(void *)philo_cycle, &var->philos[i]) != 0)
			return (2);
	}
	i = -1;
	while (++i < var->n_philos)
		if (pthread_join(var->philos[i].p_thread, NULL) != 0)
			return (2);
	// add death checker hir 
	return (0);
}
