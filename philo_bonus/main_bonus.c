/* ************************************************************************** */
/*                                                                            */
/*   main_bonus.c                                                             */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/05/30                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_end_program(t_env *env)
{
	int	i;
	int	status;

	i = -1;
	while (++i < env->amount)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			i = -1;
			while (++i < env->amount)
				kill(env->philos[i].pid, SIGTERM);
			break ;
		}
	}
	sem_close(env->message);
	sem_close(env->check);
	sem_close(env->fork);
	sem_unlink("/print");
	sem_unlink("/check");
	sem_unlink("/forks");
	free(env->philos);
}

static void	ft_basis(t_env *env)
{
	int	i;

	i = -1;
	env->start_time = ft_get_time();
	while (++i < env->amount)
	{
		env->philos[i].time_to_die = env->start_time;
		env->philos[i].pid = fork();
		if (env->philos[i].pid == -1)
			exit(EXIT_FAILURE);
		if (env->philos[i].pid == 0)
			ft_threads(&env->philos[i]);
	}
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (!ft_parser(argc, argv))
		return (0);
	ft_init(&env, argc, argv);
	ft_basis(&env);
	ft_end_program(&env);
	return (0);
}
