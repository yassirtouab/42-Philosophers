/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:59:54 by ytouab            #+#    #+#             */
/*   Updated: 2022/08/20 03:39:37 by ytouab           ###   ########.fr       */
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

// void	ft_print_params(t_data *data)
// {
// 	printf("number_of_philos: %d\n", data->number_of_philos);
// 	printf("time_to_die: %lld\n", data->time_to_die);
// 	printf("time_to_eat: %d\n", data->time_to_eat);
// 	printf("time_to_sleep: %d\n", data->time_to_sleep);
// 	if (data->ac == 6)
// 		printf("must_eat_times: %ld\n", data->must_eat_times);
// 	else
// 		printf("must_eat_times not specified\n");
// }
