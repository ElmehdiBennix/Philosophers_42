/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:13:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/02 16:01:36 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int philo(int ac, char **av)
{
    t_data var;

    if (parse(ac ,av, &var) != 0)
        return (1);
    if (init_philo(&var) != 0)
        return (2);


    return (0);
}

int main (int ac, char **av)
{
    if (ac < 5 || ac > 6)
        return (exit_msg("4 or 5 arguments are allowed.", YELLOW, 1));
    return (philo(ac, ++av));
}