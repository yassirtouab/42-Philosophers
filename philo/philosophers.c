/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:15:09 by ytouab            #+#    #+#             */
/*   Updated: 2022/08/20 19:08:04 by ytouab           ###   ########.fr       */
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
		ft_sleeping(ph);
	}
	return (NULL);
}

int	ft_philo_death(t_data *data, int i, int *exit)
{
	pthread_mutex_lock(&data->philos[i].eat_mutex);
	if ((ft_curr_time() - (data->philos[i].last_meal_time))
		>= (data->time_to_die))
	{
		ft_dead(&data->philos[i]);
		*exit = 1;
		return (1);
	}
	pthread_mutex_unlock(&data->philos[i].eat_mutex);
	return (0);
}

void	ft_monitor(t_data *data, int i, int check, int exit)
{
	while (1)
	{
		i = -1;
		check = data->must_eat_times;
		while (++i < data->number_of_philos)
		{
			check &= data->philos[i].eat_count;
			if (data->philos[i].eat_count == data->must_eat_times)
				continue ;
			if (data->philos[i].status != EATING)
			{
				if (ft_philo_death(data, i, &exit))
					return ;
			}
		}
		if (exit || check == data->must_eat_times)
			break ;
		usleep(100);
	}
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
		ft_init(&data, 0);
		ft_thread_create(&data);
		ft_monitor(&data, 0, 0, 0);
	}
	else
		ft_error(&data, 7);
	ft_exit(&data, 0);
}
