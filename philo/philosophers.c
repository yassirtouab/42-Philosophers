/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:15:09 by ytouab            #+#    #+#             */
/*   Updated: 2022/08/04 22:06:12 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *philo)
{
	(void)philo;

	t_philo	*ph;

	ph = (t_philo *)philo;
	while (ph->data->max_meals == 0 || ph->eat_count < (size_t)ph->data->max_meals)
	{
		ft_thinking(ph);
		ft_take_forks(ph);
		ft_eating(ph);
		ft_put_forks(ph);
		ft_sleeping(ph);
		printf("inside routine\n");
	}
	return (NULL);
}

int	ft_init(t_data *data)
{
	int	i;

	i = 0;
	(void)i;
	data->philos = (t_philo *)malloc(data->number_of_philos * sizeof(t_philo));
	if (!data->philos)
		return (1);
	data->fork = (pthread_mutex_t *)malloc(data->number_of_philos * sizeof(pthread_mutex_t));
	if (!data->fork)
		return (1);
	while (i < data->number_of_philos)
		if (pthread_mutex_init(&data->fork[i++], NULL) != 0)
			return (1);
	if (pthread_mutex_init(&data->event, NULL) != 0)
		return (1);
	data->start_time = ft_curr_time();
	i = -1;
	while (++i < data->number_of_philos)
	{
		data->philos[i].id = i;
		data->philos[i].status = 0;
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].eat_mutex, NULL);
	}
	return (0);
}

int	ft_simulate(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, &ft_routine, data->philos);
		usleep(60);
		// pthread_join(data->philos[i].thread, NULL);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	size_t	i;

	i = 0;
	(void)i;
	if (ac == 6 || ac == 5)
	{

		printf("TIME: |%ld|\n", ft_curr_time());
		take_args(&data, ac, av);
		ft_print_params(&data);
		ft_init(&data);
		ft_simulate(&data);
	}
	else
		ft_error(&data, 0);
	ft_exit(&data, 0);
}

