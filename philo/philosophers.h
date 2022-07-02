/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:11:50 by ytouab            #+#    #+#             */
/*   Updated: 2022/07/01 19:46:21 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

	// LIBRARIES

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

	// PHILO STATUS

# define THINKING			0
# define TOOK_FORK			1
# define EATING				2
# define SLEEPING			3
# define DEAD				4

	// COLOR CODES

# define DEFAULT			"\033[0m"
# define RED			"\033[0;31m"
# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;33m"
# define PURPLE			"\033[0;35m"
# define CYAN			"\033[0;36m"


	// STRUCTS

typedef struct s_philo
{
	struct s_data		*data;
	int					id;
	int					status;
	size_t				dead_time;
	size_t				eat_count;
	size_t				last_meal_time;
	pthread_mutex_t		eat_mutex;
	pthread_t			thread;
}					t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				dead;
	size_t			start_time;
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	int				max_meals;
	int				ac;
	pthread_mutex_t	*fork;
	pthread_mutex_t	event;
}						t_data;

/* -------------FUNCTIONS -------------*/

	//	PARSING FUNCTIONS

void	take_args(t_data *data, int ac, char **av);
int		super_atoi(const char *str, t_data *data, size_t nb, int i);
void	ft_isdigit_signs(const char *s, t_data *data, size_t i);

	//	TOOLS

void	ft_print_params(t_data *data);
void	ft_init_data(t_data *data, int ac);
void	ft_exit(t_data *data, int code);
void	ft_error(t_data *data, int error);

	//	UTILS

size_t	ft_strlen(const char *s);
int		ft_delimiter(char c, char *charset);
char	*ft_strchr(const char *str, int c);

	//	TIME

size_t	ft_curr_time(void);

#endif
