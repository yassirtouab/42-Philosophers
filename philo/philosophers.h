/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:11:50 by ytouab            #+#    #+#             */
/*   Updated: 2022/08/20 19:18:11 by ytouab           ###   ########.fr       */
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

# define DEFAULT		"\033[0m"
# define BLUE			"\033[1;34m"
# define RED			"\033[1;31m"
# define GREEN			"\033[1;32m"
# define YELLOW			"\033[1;33m"
# define PURPLE			"\033[1;35m"
# define CYAN			"\033[1;36m"

# define PH_ATE "\033[1;32m\n< All Philosophers ate \033[1;36m%d\033[1;32m times >\n"

	// STRUCTS

typedef struct s_philo
{
	struct s_data		*data;
	int					id;
	int					status;
	int					dead_time;
	int					eat_count;
	unsigned long long	last_meal_time;
	pthread_mutex_t		eat_mutex;
	pthread_t			thread;
}						t_philo;

typedef struct s_data
{
	t_philo				*philos;
	pthread_mutex_t		*fork;
	pthread_mutex_t		event;
	int					dead;
	unsigned long long	start_time;
	int					number_of_philos;
	int					time_to_eat;
	unsigned long long	time_to_die;
	int					time_to_sleep;
	int					must_eat_times;
	int					ac;
}						t_data;

/* -------------FUNCTIONS -------------*/

	//	PARSING FUNCTIONS

void		take_args(t_data *data, int ac, char **av);
int			super_atoi(const char *str, t_data *data, size_t nb, int i);
void		ft_isdigit_signs(const char *s, t_data *data, size_t i);

	//	TOOLS

void		ft_print_params(t_data *data);
void		ft_init_data(t_data *data, int ac);
void		ft_exit(t_data *data, int code);
void		ft_error(t_data *data, int error);
void		ft_print_event(t_philo *ph, int status);
void		ft_status_print(size_t time, int ph, char *event);

	//	UTILS

size_t		ft_strlen(const char *s);
int			ft_delimiter(char c, char *charset);
char		*ft_strchr(const char *str, int c);

	//	TIME

long long	ft_curr_time(void);
void		ft_usleep(long long time);

	//	EVENTS

void		ft_thinking(t_philo *ph);
void		ft_take_forks(t_philo *ph);
void		ft_eating(t_philo *ph);
void		ft_dead(t_philo *ph);
void		ft_sleeping(t_philo *ph);

void		ft_thread_create(t_data *data);
void		ft_monitor(t_data *data, int i, int check, int exit);

void		ft_print_params(t_data *data);
void		ft_init(t_data *data, int i);
#endif
