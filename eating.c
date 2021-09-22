/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:26:42 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/22 14:53:00 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	eating(t_table *table, int pos, int next)
{
	pthread_mutex_lock(&table->philo[pos].fork);
	print_msj(table, pos, "has taken a fork");
	pthread_mutex_lock(&table->philo[next].fork);
	print_msj(table, pos, "has taken a fork");
	print_msj(table, pos, "is eating");
	if (table->number_eat)
	{
		if (table->philo[pos].eat_i != 0)
			table->philo[pos].eat_i--;
		else
			table->philo[pos].check = 1;
	}
	table->philo[pos].tlast_eat = get_time_in_ms();
	ft_usleep(table->teat);
	pthread_mutex_unlock(&table->philo[pos].fork);
	pthread_mutex_unlock(&table->philo[next].fork);
}
