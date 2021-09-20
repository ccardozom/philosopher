/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:26:42 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/10 01:01:59 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	eating(t_philo *philo)
{
	if (philo->id == 1)
	{
            if (!philo->table->philo[philo->table->number_philo - 1].fork)
			{
				pthread_mutex_lock(&philo->fork_left);
			    philo->table->philo[philo->table->number_philo - 1].fork = true;
				printf("%ld\t Philo: %d Take fork left\n", philo->philo_timer, philo->id);
				philo->check_fork_left = 1;
			}
			if (!philo->table->philo[philo->id - 1].fork)
			{
				pthread_mutex_lock(&philo->fork_right);
				philo->table->philo[philo->id - 1].fork = true;
				printf("%ld\t Philo: %d Take fork right\n", philo->philo_timer, philo->id);
				philo->check_fork_right = 1;
			}	
			if (philo->check_fork_left && philo->check_fork_right)
				printf("%ld\t Philosopher %d is eating\n", philo->philo_timer, philo->id);
			exit_ctrl(philo);
		philo->table->philo[philo->table->number_philo - 1].fork = false;
		philo->table->philo[philo->id - 1].fork = false;
	}
	else
	{
		if (!philo->table->philo[philo->id - 1].fork)
		{
			pthread_mutex_lock(&philo->fork_left);
			philo->table->philo[philo->id - 1].fork = true;
            printf("%ld\t Philo: %d Take fork left\n", philo->philo_timer, philo->id);
			philo->check_fork_left = 1;
		}
		if (!philo->table->philo[philo->id].fork)
		{
			pthread_mutex_lock(&philo->fork_right);
			philo->table->philo[philo->id].fork = true;
	        printf("%ld\t Philo: %d Take fork right\n", philo->philo_timer, philo->id);
			philo->check_fork_right = 1;
		}
		if (philo->check_fork_left && philo->check_fork_right)
			printf("%ld\t Philosopher %d is eating\n", philo->philo_timer, philo->id);
		exit_ctrl(philo);
		philo->table->philo[philo->id - 1].fork = false;
		philo->table->philo[philo->id].fork = false;
	}
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(&philo->fork_right);
}
