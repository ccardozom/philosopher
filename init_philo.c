/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:24:21 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/10 00:59:19 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

int		init_philo(t_table *table)
{
	int		cont;

	table->philo = malloc(sizeof(t_philo) * table->number_philo);
	cont = 0;
	while (cont < table->number_philo)
	{
		table->philo[cont].id = cont + 1;
		table->philo->fork = false;
		table->philo[cont].table = table;
		table->philo[cont].check_fork_left = 0;
		table->philo[cont].check_fork_right = 0;
		if (table->number_eat)
			table->philo[cont].eat_count = table->number_eat;
		else
			table->philo[cont].eat_count = 0;
		table->philo[cont].life = 1;
		pthread_mutex_init(&table->philo[cont].fork_left, NULL);
		pthread_mutex_init(&table->philo[cont].fork_right, NULL);
		cont++;
	}
	return (0);
}
