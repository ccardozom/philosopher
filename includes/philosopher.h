/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:01:28 by alesanto          #+#    #+#             */
/*   Updated: 2021/09/10 00:58:04 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct		s_philo
{
	int				id;
	bool			fork;
	bool			check_fork_left;
	bool			check_fork_right;
	bool			life;
	pthread_t		thread;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
	struct s_table	*table;
	long int		philo_timer;
	long int		philo_start_time;
	int				eat_count;
}					t_philo;

typedef struct		s_table
{
	int				number_philo;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				number_eat;
	int				exit_ctrl;
	t_philo			*philo;
}					t_table;

/* --------------MAIN--------------- */

int		main(int argc, char **argv);

/* --------------INITIALIZE--------------- */

int		init_philo(t_table *table);

/* --------------TREAD--------------- */

int		init_thread(t_table *table);
void	*start_routine(void *args);
long int	get_time_in_ms(void);

/* --------------ROUTINE--------------- */

void	eating(t_philo *philo);

/* --------------CHECKERS--------------- */

int		check_arguments(int argc, char **argv, t_table *table);
int		check_philo(void *args);

/* --------------OUTILS--------------- */

char    *wrong_list(int number);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

/* --------------PRINTERS--------------- */

void	print_wrong_text(int check);

/* --------------EXIT--------------- */

void    exit_ctrl(t_philo *philo);

#endif
