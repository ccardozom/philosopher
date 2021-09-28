/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:29:22 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/22 11:24:25 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	print_msj(t_table *table, int pos, char *str)
{
	long int	time;

	time = get_time_in_ms() - table->init_program;
	pthread_mutex_lock(&table->print);
	printf("%ld %d %s\n", time, pos + 1, str);
	pthread_mutex_unlock(&table->print);
}
