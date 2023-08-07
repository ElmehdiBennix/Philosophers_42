/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:14:39 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/02 11:43:19 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	exit_msg(char *msg, char *color, int erno)
{
	printf("%s-> %s %s\n", color, msg, DEFAULT);
	//free data
	return (erno);
}