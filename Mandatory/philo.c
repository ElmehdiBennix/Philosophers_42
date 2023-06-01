/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:13:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/01 14:28:07 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int philo(int ac, char **av)
{
    t_data var;
    unsigned int i;

    i = 0;
    parse(ac ,av, &var);
    init_philos(&var);
    while (i < var.numb_of_philos)
    {
        if(pthread_create(&var.philosophers->philo, NULL ,(void *)philo_cycle, var.philosophers) != 0)
            exit_msg("error",RED,1);
        printf("%d id has been created \n", var.philosophers->id);
        var.philosophers = var.philosophers->next;
        i++;
    }
    i = 0;
    while (i < var.numb_of_philos)
    {
        if(pthread_join(var.philosophers->philo, NULL) != 0)
            exit_msg("error",RED,1);
        printf("%d id has been joined \n", var.philosophers->id);
        var.philosophers = var.philosophers->next;
        i++;
    }
    //destroy mutex after the use;
    return (0);
}

int main (int ac, char **av)
{
    int err;

    if (ac < 5 || ac > 6)
        exit_msg("4 or 5 arguments are allowed", YELLOW, 1);
    err = philo(ac, ++av);
    return (err);
}