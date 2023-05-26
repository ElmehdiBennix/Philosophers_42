/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/26 00:37:24 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static  void    get_data(t_data *var, int data, int i)
{
    if (i == 0)
        var->numb_of_philos = data;
    else if (i == 1)
        var->death_time = data;
    else if (i == 2)
        var->eating_time = data;
    else if (i == 3)
        var->sleeping_time = data;
    else if (i == 4)
        var->eating_reps = data;
}

static  void    valid_data(t_data *var)
{
    if (var->numb_of_philos > 200)
        exit_msg("Can't have more then 200 Philos.", YELLOW, 1);
    if (var->death_time < 60)
        exit_msg("Can't have time_to_die under 60 ms.", YELLOW, 1);
    if (var->eating_time < 60)
        exit_msg("Can't have time_to_eat under 60 ms.", YELLOW, 1);
    if (var->sleeping_time < 60)
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
        get_data(var, ft_atoi(*av), i);
        i++;
        av++;
    }
    valid_data(var);
    if (ac == 5)
        var->eating_reps = -1;       
}
