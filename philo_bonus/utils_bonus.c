/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:01:30 by ntojamur          #+#    #+#             */
/*   Updated: 2022/05/31 20:42:47 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	negative;
	long int	res;

	negative = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			||str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = -1;
	if (negative == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res * negative <= -2147483649)
			return (0);
		else if (res * negative >= 2147483648)
			return (-1);
		i++;
	}
	return (res * negative);
}

void	ft_usleep(time_t	now, int time)
{
	while (1)
	{
		if ((ft_get_time() - now) >= time)
			break ;
		usleep(100);
	}
}

time_t	ft_get_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return (start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
}
