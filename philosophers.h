/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:11:50 by ytouab            #+#    #+#             */
/*   Updated: 2022/04/02 07:15:19 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_philo
{
	int	id;
	
}				t_philo;

typedef struct	s_data
{
	int	nop;
	int	ttd;
	int	tte;
	int	tts;
	int	noe;
}				t_data;


int	super_atoi(const char *str, t_data *data);
int	ft_isdigit_signs(const char *s, t_data *data);

#endif
