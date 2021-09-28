/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:25:32 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/22 14:51:43 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

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
		usleep(table->teat * 1000);
	while (1)
	{
		if (table->philo[pos].check != 1)
		{
			eating(table, pos, next);
			sleeping(table, pos);
		}
	}
	return (0);
}
