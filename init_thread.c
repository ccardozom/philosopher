/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:30:00 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/10 00:14:10 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

int		init_thread(t_table *table)
{
	int				cont;

	cont = 0;
	while (cont < table->number_philo)
	{
		if (pthread_create(&table->philo[cont].thread, NULL,
			(void *)start_routine, (void *)&table->philo[cont]))
			return (1);
		cont++;
	}
	cont = 0;
	while (cont < table->number_philo)
		pthread_join(table->philo[cont++].thread, NULL);
	return (0);
}