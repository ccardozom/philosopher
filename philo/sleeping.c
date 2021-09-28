/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 07:48:51 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/22 14:51:57 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	sleeping(t_table *table, int pos)
{
	print_msj(table, pos, "is sleeping");
	ft_usleep(table->tsleep);
	print_msj(table, pos, "is thinking");
}
