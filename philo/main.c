/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:51:37 by ntojamur          #+#    #+#             */
/*   Updated: 2022/06/02 20:14:37 by ntojamur         ###   ########.fr       */
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
