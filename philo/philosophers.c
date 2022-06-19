/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:15:09 by ytouab            #+#    #+#             */
/*   Updated: 2022/06/19 18:34:31 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_args(t_data *data, int ac, char **av)
{
	size_t	i;

	i = 1;
	ft_init_data(data);
	while ((int)i < ac)
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
	gettimeofday(&current_time, NULL);
	printf("TIME: |%d|\n", current_time.tv_usec);
	take_args(&data, ac, av);
	if (ac == 6 || ac == 5)
	{
		printf("number_of_philos: %d\n", data.number_of_philos);
		printf("time_to_die: %d\n", data.time_to_die);
		printf("time_to_eat: %d\n", data.time_to_eat);
		printf("time_to_sleep: %d\n", data.time_to_sleep);
		printf("must_eat_times: %d\n", data.must_eat_times);
	}
	else
		ft_error(&data, 0);
	ft_exit(&data, 0);
}
