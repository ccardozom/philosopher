/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:58:55 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/09 12:35:58 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosopher.h"

void    exit_ctrl(t_philo *philo)
{ 
    int time;

    time = get_time_in_ms();
    sleep(1);
    if (philo->eat_count)
    {
		philo->eat_count--;
        if (!philo->eat_count)
        {
          philo->table->exit_ctrl = 1;
        }    
    }
    else
    {
        time = time -  philo->philo_timer;
        if (time > philo->table->time_to_eat)
           philo->table->exit_ctrl = 1;
    }
}