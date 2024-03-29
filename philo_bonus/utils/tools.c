/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:07:21 by ebennix           #+#    #+#             */
/*   Updated: 2023/08/10 15:30:16 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	skip(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\f')
		i++;
	return (i);
}

static int	signop(const char *str, int i, int *sign)
{
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;
	int			overflow;

	i = 0;
	sign = 1;
	res = 0;
	overflow = 0;
	i = skip(str, i);
	i = signop(str, i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res < 0)
			overflow = 1;
		i++;
	}
	if (overflow && sign == -1)
		return ((int)LONG_MIN);
	else if (overflow && sign == 1)
		return ((int)LONG_MAX);
	return (res * sign);
}
