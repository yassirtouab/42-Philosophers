/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:45:17 by ytouab            #+#    #+#             */
/*   Updated: 2022/07/12 01:45:17 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_thinking(t_philo *ph)
{
	ft_print_event(ph, THINKING);
}

void	ft_take_forks(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->fork[ph->id]);
	ft_print_event(ph, TOOK_FORK);
	pthread_mutex_lock(&ph->data->fork[(ph->id + 1)
		% ph->data->number_of_philos]);
	ph->status = EATING;
	pthread_mutex_lock(&ph->eat_mutex);
	ft_print_event(ph, TOOK_FORK);
}

void	ft_eating(t_philo *ph)
{
	ft_print_event(ph, EATING);
	ph->last_meal_time = ft_curr_time();
	ph->eat_count++;
	ft_usleep(ph->data->time_to_eat);
	pthread_mutex_unlock(&ph->eat_mutex);
	ph->status = !EATING;
}

void	ft_put_forks(t_philo *ph)
{
	pthread_mutex_unlock(&ph->data->fork[ph->id]);
	pthread_mutex_unlock(
		&ph->data->fork[(ph->id + 1) % ph->data->number_of_philos]);
}

void	ft_dead(t_philo *ph)
{
	ph->data->dead = 1;
	ft_print_event(ph, DEAD);
}

void	ft_sleeping(t_philo *ph)
{
	ft_print_event(ph, SLEEPING);
	ft_usleep(ph->data->time_to_sleep);
}
