/* ************************************************************************** */
/*                                                                            */
/*   init.c                                                                   */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/05/26                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_clean(t_env *env, int size)
{
	int	i;

	i = -1;
	if (size != 0)
		env->amount = size;
	while (++i < env->amount)
		pthread_mutex_destroy(&env->philos[i].fork);
	if (env->philos)
		free(env->philos);
	return (0);
}

static int	ft_init_forks(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->amount)
		if (pthread_mutex_init(&env->philos[i++].fork, NULL) != 0)
			return (ft_clean(env, i));
	if (pthread_mutex_init(&env->message, NULL) != 0)
		return (ft_clean(env, 0));
	return (1);
}

static int	ft_init_philos(t_env *env)
{
	int	i;

	i = -1;
	env->philos = malloc(sizeof(t_philos) * env->amount);
	if (!env->philos)
		return (0);
	while (++i < env ->amount)
	{
		env->philos[i].number = i + 1;
		env->philos[i].env = env;
		if (i == env->amount - 1)
			env->philos[i].friends_fork = &env->philos[0].fork;
		else
			env->philos[i].friends_fork = &env->philos[i + 1].fork;
		env->philos->last_eat = 0;
		env->philos[i].must_eat = env->must_eat;
	}
	return (1);
}

int	ft_init(t_env *env, int argc, char **argv)
{
	int	i;

	i = -1;
	env->amount = ft_atoi(argv[1]);
	env->time_die = ft_atoi(argv[2]);
	env->time_eat = ft_atoi(argv[3]);
	env->time_sleep = ft_atoi(argv[4]);
	env->must_eat = -1;
	if (argc == 6)
		env->must_eat = ft_atoi(argv[5]);
	if (!ft_init_philos(env))
	{
		printf("Malloc error\n");
		return (0);
	}
	if (!ft_init_forks(env))
	{
		printf("Mutex error\n");
		return (0);
	}
	return (1);
}
