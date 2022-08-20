/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:59:54 by ytouab            #+#    #+#             */
/*   Updated: 2022/08/20 21:10:08 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	ft_curr_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000LL) + (curr_time.tv_usec / 1000LL));
}

void	ft_usleep(long long time)
{
	long long	start;

	start = ft_curr_time();
	while ((ft_curr_time() - time) < start)
		usleep(100);
}

void	ft_init_data(t_data *data, int ac)
{
	data->dead = 0;
	data->start_time = 0;
	data->number_of_philos = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->must_eat_times = 0;
	data->must_eat_times = 0;
	data->ac = ac;
}

void	ft_init(t_data *data, int i)
{
	data->philos = (t_philo *)malloc(data->number_of_philos * sizeof(t_philo));
	if (!data->philos)
		ft_error(data, 4);
	data->fork = (pthread_mutex_t *)malloc(data->number_of_philos
			* sizeof(pthread_mutex_t));
	if (!data->fork)
		ft_error(data, 4);
	while (i < data->number_of_philos)
		if (pthread_mutex_init(&data->fork[i++], NULL))
			ft_error(data, 5);
	if (pthread_mutex_init(&data->event, NULL))
		ft_error(data, 5);
	data->start_time = ft_curr_time();
	i = -1;
	while (++i < data->number_of_philos)
	{
		data->philos[i].id = i;
		data->philos[i].status = 0;
		data->philos[i].eat_count = 0;
		data->philos[i].last_meal_time = ft_curr_time();
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].eat_mutex, NULL);
	}
}

void	ft_exit(t_data *data, int code)
{
	int	i;

	i = 0;
	if (!code)
	{
		if (!(data->dead) && data->ac == 6)
			printf(PH_ATE, data->must_eat_times);
		while (i < data->number_of_philos)
		{
			pthread_mutex_destroy(&data->fork[i]);
			pthread_mutex_destroy(&data->philos[i].eat_mutex);
			i++;
		}
		pthread_mutex_destroy(&data->event);
		if (data->philos)
			free(data->philos);
		if (data->fork)
			free(data->fork);
	}
	exit(code);
}
