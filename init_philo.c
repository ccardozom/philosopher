/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:24:21 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/20 15:52:34 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

int	init_philo(t_table *table)
{
	int	cont;

	table->philo = malloc(sizeof(t_philo) * table->number_philo);
	cont = 0;
	table->cont = 0;
	while (cont < table->number_philo)
	{
		table->philo[cont].id = cont + 1;
		table->philo[cont].table = table;
		if (table->number_eat)
			table->philo[cont].eat_count = table->number_eat;
		else
			table->philo[cont].eat_count = 0;
		pthread_mutex_init(&table->philo[cont].fork, NULL);
		cont++;
	}
	return (0);
}
