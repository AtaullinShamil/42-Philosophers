/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:47:52 by ntojamur          #+#    #+#             */
/*   Updated: 2022/06/02 19:56:40 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_monitor(t_env	*env)
{
	int	i;

	i = 0;
	while (i < env->amount)
	{
		if (env->philos[i].must_eat != 0)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_cycle(t_env *env)
{
	int		i;

	i = 0;
	while (ft_monitor(env))
	{
		if (i == env->amount)
			i = 0;
		pthread_mutex_lock(&env->message);
		if (ft_get_time() - env->start_time - env->philos[i].last_eat > \
			env->time_die)
		{
			printf("%ld\t%d died\n", \
				ft_get_time() - env->start_time, env->philos[i].number);
			pthread_mutex_unlock(&env->message);
			break ;
		}
		pthread_mutex_unlock(&env->message);
		i++;
	}
}

static void	ft_end(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->amount)
	{
		pthread_mutex_destroy(&env->philos[i].fork);
		i++;
	}
	pthread_mutex_destroy(&env->message);
	if (env->philos)
		free(env->philos);
}

void	ft_basis(t_env *env)
{
	int	i;

	i = -1;
	if (ft_threads(env))
	{
		ft_cycle(env);
		while (++i < env->amount)
			pthread_detach(env->philos[i].t);
	}
	else
		printf("Couldn't create a thread for philosopher\n");
	ft_end(env);
}
