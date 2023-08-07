/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:03:11 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/07 06:26:42 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	exit_msg(char *msg, char *color, int erno)
{
	printf("%s-> %s %s\n", color, msg, DEFAULT);
	//free data
	return (erno);
}

//freee data