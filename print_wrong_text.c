/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wrong_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:32:23 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/22 14:26:28 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosopher.h"

void	print_wrong_text(int check)
{
	char	*wrong_text1;
	char	*wrong_text2;

	wrong_text1 = "Wrong number of ";
	wrong_text2 = "Wrong number: ";
	if (check > 0 && check < 4)
	{
		printf("%s%s\n", wrong_text1, wrong_list(check));
		exit(-1);
	}
	else if (check > 3 && check < 7)
	{
		printf("%s%s\n", wrong_text2, wrong_list(check));
		exit(-1);
	}
}
