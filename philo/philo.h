/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:51:29 by ntojamur          #+#    #+#             */
/*   Updated: 2022/06/02 20:13:34 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos
{
	int				number;
	time_t			last_eat;
	pthread_mutex_t	fork;
	pthread_mutex_t	*friends_fork;
	struct s_env	*env;
	pthread_t		t;
	int				must_eat;
}	t_philos;

typedef struct s_env
{
	int				amount;
	int				must_eat;
	time_t			time_die;
	time_t			time_eat;
	time_t			time_sleep;
	time_t			start_time;
	t_philos		*philos;
	pthread_mutex_t	message;
}	t_env;

int		ft_parser(int argc, char **argv);
int		ft_init(t_env *env, int argc, char **argv);
void	ft_basis(t_env *env);
int		ft_threads(t_env *env);

int		ft_error(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_usleep(time_t	now, int i);
time_t	ft_get_time(void);

#endif
