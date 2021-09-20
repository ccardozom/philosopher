/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:24:27 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/20 15:45:24 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosopher.h"

char	*wrong_list(int number)
{
	char	*argument_error_cause;

	argument_error_cause = NULL;
	if (number == 1)
		argument_error_cause = "arguments";
	else if (number == 2)
		argument_error_cause = "meals";
	else if (number == 3)
		argument_error_cause = "philosopher";
	else if (number == 4)
		argument_error_cause = "time to die";
	else if (number == 5)
		argument_error_cause = "time to eat";
	else if (number == 6)
		argument_error_cause = "time to sleep";
	return (argument_error_cause);
}
