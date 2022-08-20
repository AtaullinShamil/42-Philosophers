/* ************************************************************************** */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/05/25                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (!ft_parser(argc, argv))
		return (ft_error("Error arguments"));
	if (!ft_init(&env, argc, argv))
		return (1);
	ft_basis(&env);
	return (0);
}
