/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:15:09 by ytouab            #+#    #+#             */
/*   Updated: 2022/07/01 23:01:40 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *philo)
{
	(void)philo;
	printf("inside routine\n");
	return (NULL);
}

int	ft_simulate(t_data *data)
{
	size_t	i;
	t_philo	philo[data->number_of_philos];

	i = 0;
	pthread_create(&philo[i].thread, NULL, &ft_routine, data->philos);
	// pthread_join(philo.thread, NULL);
	usleep(60);
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
		ft_simulate(&data);
	}
	else
		ft_error(&data, 0);
	ft_exit(&data, 0);
}
