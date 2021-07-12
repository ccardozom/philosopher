/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:49:41 by ccardozo          #+#    #+#             */
/*   Updated: 2021/07/08 01:53:40 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosopher.h"

int		check_arguments(int argc, char **argv, t_base *base)
{
    int wrong_check;
    char    *wrong_text1;
    char    *wrong_text2;
    
    wrong_check = 0;
    wrong_text1 = "Wrong number of ";
    wrong_text2 = "Wrong number: ";
	if (argc < 5 || argc > 6)
		wrong_check = 1;
	else if ((base->nb_ph = ft_atoi(argv[1])) < 2)
		wrong_check = 2;
	else if (argc == 6 && (base->nb_eat = ft_atoi(argv[5])) < 0)
		wrong_check = 3;
	else if ((base->t_die = ft_atoi(argv[2])) < 60)
		wrong_check = 4;
	else if ((base->t_eat = ft_atoi(argv[3])) < 20)
		wrong_check = 5;
	else if ((base->t_sleep = ft_atoi(argv[4])) < 60)
		wrong_check = 6;
	// else
	// 	return (init_philo(base));
	if (wrong_check > 0 && wrong_check < 4)
		printf("%s%s\n", wrong_text1, wrong_list(wrong_check));
	else if (wrong_check > 3 && wrong_check < 7)
		printf("%s%s\n", wrong_text2, wrong_list(wrong_check));
	return (1);
}