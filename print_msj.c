/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:29:22 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/20 15:50:12 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	print_msj(t_table *table, int pos, char *str)
{
	long int	time;

	time = get_time_in_ms();
	time = time - table->philo->philo_start_time;
	pthread_mutex_lock(&table->print);
	printf("%ld Philo: %d %s\n", time, pos + 1, str);
	pthread_mutex_unlock(&table->print);
}
