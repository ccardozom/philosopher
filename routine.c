/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:25:32 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/20 15:49:02 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	sleeping(t_table *table)
{
	long int	time;

	time = get_time_in_ms();
	usleep(table->time_to_sleep * 1000);
	printf("%ld Philo: %d is sleeping...\n",
		time - table->philo->philo_start_time, table->philo->id);
}

void	*start_routine(void *data)
{
	t_table	*table;
	int		pos;
	int		next;

	table = (t_table *)data;
	pos = table->cont++;
	if (pos == table->number_philo - 1)
		next = 0;
	else
		next = pos + 1;
	if (pos % 2 != 0)
		usleep(table->time_to_eat * 1000);
	while (1)
	{	
		eating(table, pos, next);
		sleeping(table);
	}
	return (0);
}
