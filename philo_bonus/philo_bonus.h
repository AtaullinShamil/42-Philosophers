/* ************************************************************************** */
/*                                                                            */
/*   philo_bonus.h                                                            */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/05/30                                                      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_philos
{
	int				number;
	int				must_eat;
	int				eaten_meals;
	time_t			last_eat;
	time_t			time_to_die;
	struct s_env	*env;
	pid_t			pid;
	pthread_t		t;
}	t_philos;

typedef struct s_env
{
	int			amount;
	int			must_eat;
	int			dead;
	time_t		time_die;
	time_t		time_eat;
	time_t		time_sleep;
	time_t		start_time;
	t_philos	*philos;
	sem_t		*message;
	sem_t		*check;
	sem_t		*fork;
}	t_env;

int		ft_parser(int argc, char **argv);
void	ft_init(t_env *env, int argc, char **argv);
void	ft_threads(t_philos *philos);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_usleep(time_t	now, int time);
time_t	ft_get_time(void);

void	ft_forks(t_philos *philos);
void	ft_eat(t_philos *philos);
void	ft_sleep(t_philos *philos);
void	ft_think(t_philos *philos);

#endif
