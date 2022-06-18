/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:11:50 by ytouab            #+#    #+#             */
/*   Updated: 2022/06/18 22:20:18 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					id;
	int					status;
	size_t				dead_time;
	size_t				eat_count;
	size_t				last_meal_time;
	struct s_data		*data;
	pthread_mutex_t		eat_mutex;
}					t_philo;

typedef struct s_data
{
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	logger;
	t_philo			*philos;
	size_t			start_time;
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	int				max_meals;
}						t_data;

	//	PARSING FUNCTIONS

int		super_atoi(const char *str, t_data *data, size_t nb, int i);
void	ft_isdigit_signs(const char *s, t_data *data);

	//	TOOLS

void	ft_exit(t_data *data, int code);
void	ft_error(t_data *data, int error);
size_t	ft_strlen(const char *s);
int		ft_delimiter(char c, char *charset);
char	*ft_strchr(const char *str, int c);

#endif
