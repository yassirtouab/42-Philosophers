/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:40:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/08/20 21:09:15 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_error(t_data *data, int error)
{
	if (error == 1)
		write(2, RED"Error:\033[1;33m Enter a valid number\n", 42);
	else if (error == 2)
		write(2, RED"Error:\033[1;33m Negative argument\n", 39);
	else if (error == 3)
		write(2, RED"Error:\033[1;33m Argument overflowing max int\n", 50);
	else if (error == 4)
		write(2, RED"Error:\033[1;33m Memory Allocation Failed\n", 46);
	else if (error == 5)
		write(2, RED"Error:\033[1;33m Mutex initiation Failed\n", 46);
	else if (error == 6)
		write(2, RED"Error:\033[1;33m Thread Creation Failed\n", 44);
	else if (error == 7)
		write(2, RED"Error:\033[1;33m Wrong number of arguments\n", 48);
	ft_exit(data, error);
}

void	ft_print_event(t_philo *ph, int status)
{
	char	*event;

	pthread_mutex_lock(&ph->data->event);
	if (status == THINKING)
		event = PURPLE"is thinking";
	else if (status == TOOK_FORK)
		event = YELLOW"has taken a fork";
	else if (status == EATING)
		event = GREEN"is eating";
	else if (status == SLEEPING)
		event = CYAN"is sleeping";
	else if (status == DEAD)
	{
		ft_status_print(ft_curr_time() - ph->data->start_time,
			ph->id + 1, RED"died");
		return ;
	}
	ft_status_print(ft_curr_time() - ph->data->start_time, ph->id + 1, event);
	pthread_mutex_unlock(&ph->data->event);
}

void	ft_status_print(size_t time, int ph, char *event)
{
	printf(GREEN" ✓  ");
	printf(BLUE"%zu\033[1;32m m/s ", time);
	printf(" Philosopher ");
	printf("[\033[1;34m%d\033[1;32m]  "DEFAULT, ph);
	printf("%s\n"DEFAULT, event);
}

void	ft_print_params(t_data *data)
{
	printf("number_of_philos: %d\n", data->number_of_philos);
	printf("time_to_die: %lld\n", data->time_to_die);
	printf("time_to_eat: %d\n", data->time_to_eat);
	printf("time_to_sleep: %d\n", data->time_to_sleep);
	if (data->ac == 6)
		printf("must_eat_times: %d\n", data->must_eat_times);
	else
		printf("must_eat_times not specified\n");
}
