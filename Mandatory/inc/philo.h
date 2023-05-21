/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:12:33 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/21 17:27:41 by ebennix          ###   ########.fr       */
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

typedef struct s_data{
    unsigned int    n_philo;
    unsigned int    death_time;
    unsigned int    eat_time;
    unsigned int    time_to_sleep;
    int    number_of_time_philo_eats;

}               t_data;

void    parse(int ac, char **av, t_data *var);
int	    ft_isdigit(char c);
void	exit_msg(char *msg, char *color, int erno);

#endif
