/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:30:00 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/22 14:26:32 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	control_eat_i(t_table *table)
{
	int	i;

	i = -1;
	table->all_eat = 0;
	while (++i < table->number_philo)
	{
		if (table->philo[i].check == 1)
			table->all_eat++;
	}
}

void	exit_program(t_table *table, int i, int signal)
{
	pthread_mutex_lock(&table->print);
	if (signal == 1)
	{
		printf("%ld %d %s\n",
			get_time_in_ms() - table->philo[i].tlast_eat, i + 1, "died");
	}
	else if (signal == 2)
	{
		printf("%ld %s\n",
			get_time_in_ms() - table->init_program, "All philo are happy");
	}
	if (table->philo)
	{
		free(table->philo);
	}
	exit(0);
}

void	control_routine(void *data)
{
	t_table	*table;
	int		i;

	table = (void *)data;
	while (1)
	{
		control_eat_i(table);
		i = -1;
		while (++i < table->number_philo)
		{
			if (get_time_in_ms() > table->philo[i].tlast_eat + table->tdie)
				exit_program(table, i, 1);
			if (table->number_eat)
			{
				if (table->philo[i].check == 1
					&& table->all_eat == table->number_philo)
					exit_program(table, i, 2);
			}
		}
	}
}

int	init_thread(t_table *table)
{
	int			cont;
	pthread_t	thread_aux;

	cont = 0;
	while (cont < table->number_philo)
	{
		table->philo[cont].tlast_eat = table->init_program;
		if (pthread_create(&table->philo[cont].thread, NULL,
				(void *)start_routine, table))
			return (1);
		cont++;
	}
	pthread_create(&thread_aux, NULL, (void *)control_routine, table);
	pthread_join(thread_aux, NULL);
	return (0);
}
