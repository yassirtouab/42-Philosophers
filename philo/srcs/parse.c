/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:55:24 by ytouab            #+#    #+#             */
/*   Updated: 2022/06/18 22:22:12 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_isdigit_signs(const char *s, t_data *data)
{
	size_t	i;

	i = 0;
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
	while (ft_delimiter(str[i], " \t\v\r\f\n"))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && (str[i + 1] != '0'))
			ft_error(data, 2);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - 48;
		if (nb > 2147483647)
			ft_error(data, 3);
	}
	while (str[i])
	{
		if (!ft_delimiter(str[i], " \t\v\r\f\n"))
			ft_error(data, 1);
		i++;
	}
	return (nb);
}
