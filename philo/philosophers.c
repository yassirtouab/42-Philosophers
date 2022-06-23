/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:15:09 by ytouab            #+#    #+#             */
/*   Updated: 2022/06/23 16:58:52 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_args(t_data *data, int ac, char **av)
{
	int	i;

	i = 1;
	ft_init_data(data, ac);
	while (i < ac)
	{
		ft_isdigit_signs(av[i], data, 0);
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
	t_data			data;
	size_t			i;
	struct timeval	current_time;

	i = 0;
	(void)i;
	if (ac == 6 || ac == 5)
	{
		gettimeofday(&current_time, NULL);
		printf("TIME: |%ld|\n", (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
		take_args(&data, ac, av);
		ft_print_params(&data);
	}
	else
		ft_error(&data, 0);
	ft_exit(&data, 0);
}
