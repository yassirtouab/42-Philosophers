/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:40:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/06/19 18:00:16 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_exit(t_data *data, int code)
{
	(void)data;
	exit(code);
}

void	ft_error(t_data *data, int error)
{
	if (error == 0)
		write(2, "Error: Wrong number of arguments\n", 34);
	else if (error == 1)
		write(2, "Error: Enter a valid number\n", 29);
	else if (error == 2)
		write(2, "Error: Negative argument detected\n", 35);
	else if (error == 3)
		write(2, "Error: Argument overflowing max int\n", 49);
	ft_exit(data, 1);
}

void	ft_init_data(t_data *data)
{
	data->dead = 0;
	data->start_time = 0;
	data->number_of_philos = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->must_eat_times = 0;
	data->max_meals = 0;
}
