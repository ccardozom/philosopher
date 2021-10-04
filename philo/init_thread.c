/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:30:00 by ccardozo          #+#    #+#             */
/*   Updated: 2021/10/04 15:53:43 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

int	exit_program(t_table *table, int i, int signal)
{
	int	cont;

	cont = 0;
	while (cont < table->number_philo)
	{
		pthread_detach(table->philo[cont].thread);
		cont++;
	}
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
	 return (1);
}

int	control_routine(void *data)
{
	t_table	*table;
	int		i;

	table = (void *)data;
	while (!table->its_die)
	{
		i = -1;
		while (++i < table->number_philo)
		{
			if (table->number_eat)
			{
				if (table->all_eat == table->number_philo)
					return (exit_program(table, i, 2));
			}
			else if (get_time_in_ms() > table->philo[i].tlast_eat + table->tdie)
			{
				table->its_die = 1;
				return (exit_program(table, i, 1));
			}
		}
	}
	return (0);
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
	cont = 0;
	if (pthread_create(&thread_aux, NULL, (void *)control_routine, table) != 0)
		return (1);
	pthread_join(thread_aux, NULL);
	return (0);
}
