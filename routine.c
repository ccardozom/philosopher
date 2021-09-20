/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:25:32 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/10 00:16:58 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	*start_routine(void *data)
{
	t_philo *philo;
	
	philo = (t_philo *)data;
	philo->philo_start_time = get_time_in_ms();
	while (!philo->table->exit_ctrl)
	{
		eating(philo);
	}
	return (0);
}
