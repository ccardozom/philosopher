/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:49:41 by ccardozo          #+#    #+#             */
/*   Updated: 2021/09/22 14:51:57 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosopher.h"

void	save_arguments(t_table *table, int argc, char **argv)
{
	table->number_philo = ft_atoi(argv[1]);
	table->tdie = ft_atoi(argv[2]);
	table->teat = ft_atoi(argv[3]);
	table->tsleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->number_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&table->print, NULL);
	table->init_program = get_time_in_ms();
}

int	check_arguments(int argc, char **argv, t_table *table)
{
	int	wrong_check;

	wrong_check = 0;
	if (argc < 5 || argc > 6)
	{
		wrong_check = 1;
		print_wrong_text(wrong_check);
		return (1);
	}
	save_arguments(table, argc, argv);
	if (argc == 6 && (table->number_eat < 0))
		wrong_check = 2;
	else if (table->tdie < 60 || table->tdie > RAND_MAX)
		wrong_check = 4;
	else if (table->teat < 60 || table->teat > RAND_MAX)
		wrong_check = 5;
	else if (table->tsleep < 60 || table->tsleep > RAND_MAX)
		wrong_check = 6;
	else
		return (init_philo(table));
	print_wrong_text(wrong_check);
	return (1);
}
