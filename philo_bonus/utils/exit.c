/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:03:11 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/13 01:31:16 by ebennix          ###   ########.fr       */
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
// 	sem_destroy(var->fork);
// 	sem_destroy(var->print);
// 	sem_destroy(var->death);
// 	if (var->eating_reps != -1)
// 		sem_destroy(var->satisfied);
// }
