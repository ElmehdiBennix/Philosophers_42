/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:12:33 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/21 18:30:43 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include "colors.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

// they can do only one thing at a time
// number of forks is same as philos
// when they eat they put back the fork and sleep
// to eat u need 2 forks
// all should eat cant starve and die
// cant know if philo is about to die
// dont speak with the other philo

typedef struct  s_philo{
    unsigned int    id;
    pthread_t       philo;

}               t_philo;

typedef struct s_data{
    t_philo         *philosophers;
    unsigned int    numb_of_philos;
    unsigned int    death_time;
    unsigned int    eating_time;
    unsigned int    sleeping_time;
    int             eating_reps;

}               t_data;

void    parse(int ac, char **av, t_data *var);
int	    ft_isdigit(char c);
void	exit_msg(char *msg, char *color, int erno);
void init_philos(t_data *var);

#endif
