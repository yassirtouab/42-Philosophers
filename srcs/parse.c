/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:55:24 by ytouab            #+#    #+#             */
/*   Updated: 2022/04/03 09:03:42 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_isdigit_signs(const char *s, t_data *data)
{
	size_t	i;

	i = 0;
	if (!s || !ft_strlen(s))
		ft_error(data);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9')
			&& !(s[i] == '-' || s[i] == '+' || s[i] == ' '))
			ft_error(data);
		i++;
	}
	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (i == ft_strlen(s))
		ft_error(data);
	return (1);
}

int	super_atoi(const char *str, t_data *data)
{
	int	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] != '0')
			ft_error(data);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - 48;
		if (nb > 2147483647)
			ft_error(data);
	}
	return (nb);
}
