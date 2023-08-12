/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:03:11 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/11 20:07:26 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	exit_msg(char *msg, char *color, int erno)
{
	printf("%s-> %s %s\n", color, msg, DEFAULT);
	return (erno);
}

// void	data_destroyer(t_data *var)
// {
// 	int	i;

// 	i = -1;
// 	pthread_mutex_destroy(&var->print);
// 	while (++i < var->n_philos)
// 		pthread_mutex_destroy(&var->philos[i].l_fork);
// }
