/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:30:00 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/20 15:52:17 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	control_routine(void *data)
{
	t_table	*table;

	table = (void *)data;
}

int	init_thread(t_table *table)
{
	int			cont;
	pthread_t	thread_aux;

	pthread_create(&thread_aux, NULL, (void *)control_routine, table);
	pthread_join(thread_aux, NULL);
	cont = 0;
	while (cont < table->number_philo)
	{
		table->philo[cont].philo_start_time = get_time_in_ms();
		if (pthread_create(&table->philo[cont].thread, NULL,
				(void *)start_routine, table))
			return (1);
		cont++;
	}
	cont = 0;
	while (cont < table->number_philo)
		pthread_join(table->philo[cont++].thread, NULL);
	return (0);
}
