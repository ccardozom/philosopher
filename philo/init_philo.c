/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:24:21 by ccardozo          #+#    #+#             */
/*   Updated: 2021/10/04 15:59:41 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

int	init_philo(t_table *table)
{
	int	cont;

	table->philo = malloc(sizeof(t_philo) * table->number_philo);
	if (!table->philo)
		return (1);
	cont = 0;
	table->cont = 0;
	table->its_die = 0;
	pthread_mutex_init(&table->m_cont, NULL);
	while (cont < table->number_philo)
	{
		if (table->number_eat)
			table->philo[cont].eat_i = table->number_eat;
		else
			table->philo[cont].eat_i = 0;
		table->philo[cont].check = 0;
		pthread_mutex_init(&table->philo[cont].fork, NULL);
		cont++;
	}
	return (0);
}
