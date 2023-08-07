/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:47:27 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/07 06:32:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	get_data(t_data *var, int data, int i)
{
	if (i == 0)
		var->n_philos = data;
	else if (i == 1)
		var->death_t = data;
	else if (i == 2)
		var->eating_t = data;
	else if (i == 3)
		var->sleeping_t = data;
	else if (i == 4)
		var->eating_reps = data;
}

static int	valid_data(t_data *var)
{
	if (var->n_philos > 200)
		return (exit_msg(EXIT_1, YELLOW, 2));
	if (var->death_t < 60)
		return (exit_msg(EXIT_2, YELLOW, 2));
	if (var->eating_t < 60)
		return (exit_msg(EXIT_3, YELLOW, 2));
	if (var->sleeping_t < 60)
		return (exit_msg(EXIT_4, YELLOW, 2));
	if (var->n_philos == 1)
	{
		printf("-> 0 ms philo 1 died.\n");
		return (2);
	}
	return (0);
}

int	parse(int ac, char **av, t_data *var)
{
	int		i;
	char	*tmp;

	i = 0;
	while (av && i != ac - 1)
	{
		tmp = *av;
		while (*tmp)
		{
			if (!ft_isdigit(*tmp))
				return (exit_msg("Error Invalid arguments.", RED, 1));
			tmp++;
		}
		get_data(var, ft_atoi(*av), i);
		i++;
		av++;
	}
	if (valid_data(var) == 2)
		return (1);
	if (ac == 5)
		var->eating_reps = -1;
	return (0);
}
