/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 08:25:36 by ebennix           #+#    #+#             */
/*   Updated: 2023/06/02 11:55:51 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

//Regular text COLORS

# define DEFAULT "\033[0;37m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

//exit error text

# define EXIT_1 "Can't have more then 200 Philos."
# define EXIT_2 "Can't have time_to_die under 60 ms."
# define EXIT_3 "Can't have time_to_eat under 60 ms."
# define EXIT_4 "Can't have time_to_sleep under 60 ms."

#endif