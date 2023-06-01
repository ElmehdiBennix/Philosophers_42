/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:12:33 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/01 14:29:48 by ebennix          ###   ########.fr       */
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
# include <stdbool.h>
# include <limits.h>

// they can do only one thing at a time
// number of forks is same as philos
// when they eat they put back the fork and sleep
// to eat u need 2 forks
// all should eat cant starve and die
// cant know if philo is about to die
// dont speak with the other philo

// typedef struct s_time {
//     time_t       t_sec;   /* seconds since Jan. 1, 1970 */
//     suseconds_t  t_usec;  /* and microseconds */

// } t_time;


typedef struct s_list {
    int                 id;
    pthread_t           philo;
    pthread_mutex_t     fork;
    pthread_mutex_t     print;
    int                 n_eat;
    long                last_eat;
    bool                death;
    struct s_data       *var;
    struct s_list       *next;
}              t_list;

typedef struct s_data{
    t_list         *philosophers;
    unsigned int    numb_of_philos;
    unsigned int    death_time;
    unsigned int    eating_time;
    unsigned int    sleeping_time;
    int             eating_reps;

}               t_data;

int	    ft_isdigit(char c);
void    init_philos(t_data *var);
void    parse(int ac, char **av, t_data *var);
void	exit_msg(char *msg, char *color, int erno);
t_list	*ft_lstnew(int id);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstcreate_front(t_list **lst, int id);
void	ft_lstcreate_back(t_list **lst, int id);
void	ft_lstfree(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	    ft_atoi(const char *str);

void    philo_cycle(t_list *philo);


#endif
