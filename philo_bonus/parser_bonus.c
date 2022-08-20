/* ************************************************************************** */
/*                                                                            */
/*   parser_bonus.c                                                           */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/05/30                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_check_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_check_max(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_parser(int argc, char **argv)
{
	while (1)
	{
		if (argc != 5 && argc != 6)
			break ;
		if (!ft_check_digits(argv))
			break ;
		if (!ft_check_max(argv))
			break ;
		return (1);
	}
	printf("Error argument\n");
	return (0);
}

/*	if (argc != 5 && argc != 6)
		return (0);
	if (!ft_check_digits(argv))
		return (0);
	if (!ft_check_max(argv))
		return (0);
	return (1); */
