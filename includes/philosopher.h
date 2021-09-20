/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:01:28 by alesanto          #+#    #+#             */
/*   Updated: 2021/09/20 15:57:45 by ccardozo         ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct s_table	*table;
	int				fork_philo;
	long int		philo_timer;
	long int		philo_start_time;
	int				eat_count;
}					t_philo;

typedef struct s_table
{
	int				number_philo;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				number_eat;
	int				cont;
	t_philo			*philo;
	pthread_mutex_t	print;
}					t_table;

/* --------------MAIN--------------- */

int			main(int argc, char **argv);

/* --------------INITIALIZE--------------- */

int			init_philo(t_table *table);

/* --------------TREAD--------------- */

int			init_thread(t_table *table);
void		*start_routine(void *args);
long int	get_time_in_ms(void);

/* --------------ROUTINE--------------- */

void		eating(t_table *table, int left, int right);

/* --------------CHECKERS--------------- */

int			check_arguments(int argc, char **argv, t_table *table);
int			check_philo(void *args);

/* --------------OUTILS--------------- */

char		*wrong_list(int number);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);

/* --------------PRINTERS--------------- */

void		print_wrong_text(int check);
void		print_msj(t_table *table, int pos, char *str);

/* --------------EXIT--------------- */
#endif
