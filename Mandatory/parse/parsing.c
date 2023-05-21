/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/21 17:42:06 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    get_data(t_data *var, int data, int i)
{
    if (i == 0)
        var->n_philo = data;
    else if (i == 1)
        var->death_time = data;
    else if (i == 2)
        var->eat_time = data;
    else if (i == 3)
        var->time_to_sleep = data;
    else if (i == 4)
        var->number_of_time_philo_eats = data;
}

void    valid_data(t_data *var)
{
    if (var->n_philo > 200)
        exit_msg("Can't have more then 200 Philos.", YELLOW, 1);
    if (var->eat_time < 60)
        exit_msg("Can't have time_to_eat under 60 ms.", YELLOW, 1);
    if (var->death_time < 60)
        exit_msg("Can't have time_to_die under 60 ms.", YELLOW, 1);
    if (var->time_to_sleep < 60)
        exit_msg("Can't have time_to_sleep under 60 ms.", YELLOW, 1);
}

void    parse(int ac, char **av, t_data *var)
{
    int     i;
    char *tmp;

    i = 0;
    while(av && i != ac - 1)
    {
        tmp = *av;
        while(*tmp)
        {
            if (!ft_isdigit(*tmp))
                exit_msg("error", RED, 2);
            tmp++;
        }
        get_data(var,atoi(*av),i);
        i++;
        av++;
    }
    valid_data(var);
    if (ac == 5)
        var->number_of_time_philo_eats = -1;       
}