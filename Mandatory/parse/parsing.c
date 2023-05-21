/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/19 21:25:45 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void parse(int ac, char **av)
{
    char *tmp;
    int i;

    i = 0;
    while(av && i != ac - 1)
    {
        tmp = *av;
        printf("this is the av = %s \n", *av);
        while(*tmp)
        {
            if (!ft_isdigit(*tmp))
                exit_msg("error",RED,2);
            tmp++;
        }
        i++;
        av++;
    }

}