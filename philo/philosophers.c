/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:15:09 by ytouab            #+#    #+#             */
/*   Updated: 2022/06/18 20:41:28 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_args(t_data *data, int ac, char **av)
{
	size_t	i;

	i = 1;
	while ((int)i < ac)
	{
		ft_isdigit_signs(av[i], data);
		super_atoi(av[i], data, 0, 0);
		i++;
	}
	data->number_of_philos = super_atoi(av[1], data, 0, 0);
	data->time_to_die = super_atoi(av[2], data, 0, 0);
	data->time_to_eat = super_atoi(av[3], data, 0, 0);
	data->time_to_sleep = super_atoi(av[4], data, 0, 0);
	if (ac == 6)
		data->must_eat_times = super_atoi(av[5], data, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	data;
	size_t	i;

	i = 0;
	take_args(&data, ac, av);
	if (ac == 6 || ac == 5)
	{
	}
	else
		ft_error(&data, 0);
	ft_exit(&data, 0);
}
