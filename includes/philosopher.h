/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:01:28 by alesanto          #+#    #+#             */
/*   Updated: 2021/09/22 14:51:57 by ccardozo         ###   ########.fr       */
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
	pthread_t		thread;
	pthread_mutex_t	fork;
	long int		tlast_eat;
	int				eat_i;
	int				check;
}					t_philo;

typedef struct s_table
{
	long int		init_program;
	int				number_philo;
	int				tsleep;
	int				teat;
	int				tdie;
	int				number_eat;
	int				all_eat;
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
void		sleeping(t_table *table, int pos);

/* --------------CHECKERS--------------- */

int			check_arguments(int argc, char **argv, t_table *table);
int			check_philo(void *args);

/* --------------OUTILS--------------- */

char		*wrong_list(int number);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
void		ft_usleep(long int time);

/* --------------PRINTERS--------------- */

void		print_wrong_text(int check);
void		print_msj(t_table *table, int pos, char *str);

/* --------------EXIT--------------- */
#endif
