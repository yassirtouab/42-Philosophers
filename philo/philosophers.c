/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:15:09 by ytouab            #+#    #+#             */
/*   Updated: 2022/08/20 04:17:56 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (ph->data->ac != 6
		|| ph->eat_count < ph->data->must_eat_times)
	{
		ft_thinking(ph);
		ft_take_forks(ph);
		ft_eating(ph);
		ft_put_forks(ph);
		ft_sleeping(ph);
	}
	return (NULL);
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

void	clean_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philos[i].eat_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->event);
}

void	ft_supervise(t_data *data)
{
	int		i;
	int		flag;
	char		quit;

	quit = 0;
	while (1)
	{
		i = -1;
		flag = data->must_eat_times;
		while (++i < data->number_of_philos)
		{
			flag &= data->philos[i].eat_count;
			if (data->philos[i].eat_count == data->must_eat_times)
				continue ;
			if (data->philos[i].status != EATING)
			{
				pthread_mutex_lock(&data->philos[i].eat_mutex);
				if ((ft_curr_time() - (data->philos[i].last_meal_time)) >= (data->time_to_die))
				{
					ft_dead(&data->philos[i]);
					quit = 1;
					break ;
				}
				pthread_mutex_unlock(&data->philos[i].eat_mutex);
			}
		}
		if (quit)
			break ;
		if (flag == data->must_eat_times)
			break ;
		usleep(100);
	}
	clean_data(data);
}

void	ft_thread_create(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&ft_routine, &data->philos[i]) != 0)
			ft_error(data, 6);
		usleep(60);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	size_t	i;

	i = 0;
	(void)i;
	if (ac == 6 || ac == 5)
	{
		take_args(&data, ac, av);
		// ft_print_params(&data);
		ft_init(&data, 0);
		ft_thread_create(&data);
		ft_supervise(&data);
		// ft_print_params(&data);
	}
	else
		ft_error(&data, 0);
	ft_exit(&data, 0);
}
