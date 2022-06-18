/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:40:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/06/18 22:20:04 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == 0)
		return ((char *)str);
	return (0);
}

int	ft_delimiter(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

void	ft_exit(t_data *data, int code)
{
	(void)data;
	exit(code);
}

void	ft_error(t_data *data, int error)
{
	if (error == 0)
		write(2, "Error: Wrong number of arguments\n", 34);
	else if (error == 1)
		write(2, "Error: Enter a valid number\n", 29);
	else if (error == 2)
		write(2, "Error: Negative argument detected\n", 35);
	else if (error == 3)
		write(2, "Error: Arguments are overflowing max int\n", 49);
	ft_exit(data, 1);
}
