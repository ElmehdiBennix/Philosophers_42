/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:12:33 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/07 06:02:22 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include "colors.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_philo {
    unsigned int        id;
    pthread_t           p_thread;
    pthread_mutex_t     *r_fork;
    pthread_mutex_t     l_fork;
    int                 meals_n;
    long long           last_meal;
    pthread_mutex_t     print;
    struct s_data       *var;
}              t_philo;

typedef struct s_data{
    t_philo         *philos;
    unsigned int    n_philos;
    unsigned int    death_t;
    unsigned int    eating_t;
    unsigned int    sleeping_t;
    int             eating_reps;
    long long       start_clock;
    bool            stop;
	pthread_mutex_t death;
}               t_data;


#define TRUE 1
#define FALSE 0

# define take "has taken a fork"
# define eat "is eating"
# define sleep "is sleeping"
# define think "is thinking"

int	        ft_isdigit(char c);
int	        init_philo(t_data *var);
int         parse(int ac, char **av, t_data *var);
int	        exit_msg(char *msg, char *color, int erno);
int	        ft_atoi(const char *str);
long long   get_time(long long start_time);

void    philo_cycle(t_philo *philo);


#endif