/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:13:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/19 17:02:13 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo(int ac, char **av)
{
    data *philo;

    philo = malloc(sizeof(data));
    if (!philo)
        exit_msg("Memory problem !!", RED, 1);
    parse(++av);

    return (0);
}

int main (int ac, char **av)
{
    int err;

    if (ac != 4 || ac != 5)
        exit_msg("4 or 5 arguments are allowed", RED, 1);
    err = philo(ac, av);
    return (err);
}