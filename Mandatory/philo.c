/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:13:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/21 17:27:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int philo(int ac, char **av)
{
    t_data *var;

    var = malloc(sizeof(t_data));
    if (!var)
        exit_msg("Memory problem !!", RED, 1);
    parse(ac ,av, var);
    printf("%d\n",var->n_philo);
    printf("%d\n",var->death_time);
    printf("%d\n",var->eat_time);
    printf("%d\n",var->time_to_sleep);
    printf("%d\n",var->number_of_time_philo_eats);
    return (0);
}

int main (int ac, char **av)
{
    int err;

    if (ac < 5 || ac > 6)
        exit_msg("4 or 5 arguments are allowed", RED, 1);
    err = philo(ac, ++av);
    return (err);
}