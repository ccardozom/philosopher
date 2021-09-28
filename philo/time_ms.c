/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:29:07 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/20 15:46:00 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

long int	get_time_in_ms(void)
{
	struct timeval	time;
	long int		i;

	gettimeofday(&time, NULL);
	i = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (i);
}
