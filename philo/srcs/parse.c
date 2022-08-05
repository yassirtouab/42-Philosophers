/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:55:24 by ytouab            #+#    #+#             */
/*   Updated: 2022/07/12 01:33:33 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_isdigit_signs(const char *s, t_data *data, size_t i)
{
	if (!s || !ft_strlen(s))
		ft_error(data, 1);
	while (ft_delimiter(s[i], " \t\v\r\f\n"))
		i++;
	if (ft_delimiter(s[i], "-+"))
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
	{
		ft_error(data, 1);
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		i++;
	while (s[i])
	{
		if (!ft_delimiter(s[i], " \t\v\r\f\n"))
			ft_error(data, 1);
		i++;
	}
	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (i == ft_strlen(s))
		ft_error(data, 1);
}

int	super_atoi(const char *str, t_data *data, size_t nb, int i)
{
	int		sym;

	sym = 1;
	while (ft_delimiter(str[i], " \t\v\r\f\n"))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sym = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - 48;
		if (sym == 1 && nb > 2147483647)
			ft_error(data, 3);
		else if (sym == -1 && nb > 0)
			ft_error(data, 2);
	}
	return (nb * sym);
}

void	take_args(t_data *data, int ac, char **av)
{
	int	i;

	i = 1;
	ft_init_data(data, ac);
	while (i < ac)
	{
		ft_isdigit_signs(av[i], data, 0);
		super_atoi(av[i], data, 0, 0);
		i++;
	}
	data->number_of_philos = super_atoi(av[1], data, 0, 0);
	data->time_to_die = super_atoi(av[2], data, 0, 0);
	data->time_to_eat = super_atoi(av[3], data, 0, 0);
	data->time_to_sleep = super_atoi(av[4], data, 0, 0);
	if (ac == 6)
		data->must_eat_times = super_atoi(av[5], data, 0, 0);
}
