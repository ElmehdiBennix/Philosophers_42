/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:13:14 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/08 07:43:17 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int	main(int ac, char **av)
{
	t_data	var;

	if (ac == 5 || ac == 6)
	{
		if (parse(ac, ++av, &var) != 0)
			return (1);
		if (init_philo(&var) != 0)
			return (2);
		data_destroyer(&var);
		return (0);
	}
	return (exit_msg("4 or 5 arguments are allowed.", YELLOW, 1));
}