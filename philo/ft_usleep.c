/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:19:55 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/22 14:20:13 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	ft_usleep(long int time)
{
	long int	system_time;

	system_time = get_time_in_ms();
	while (get_time_in_ms() < (system_time + time))
		usleep(60);
}
