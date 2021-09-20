/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:26:42 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/20 15:54:06 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	eating(t_table *table, int pos, int next)
{
	pthread_mutex_lock(&table->philo[pos].fork);
	print_msj(table, pos, "Take fork left");
	pthread_mutex_lock(&table->philo[next].fork);
	print_msj(table, pos, "Take fork right");
	print_msj(table, pos, "Is eating...");
	usleep(table->time_to_eat * 1000);
	pthread_mutex_unlock(&table->philo[pos].fork);
	pthread_mutex_unlock(&table->philo[next].fork);
}
