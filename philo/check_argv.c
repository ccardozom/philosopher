/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:49:41 by ccardozo          #+#    #+#             */
/*   Updated: 2021/10/04 11:21:03 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosopher.h"

int	parser_arguments(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (ft_strlen(argv[i]) > 3)
		return (1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	save_arguments(t_table *table, int argc, char **argv)
{
	if (parser_arguments(argv))
		return (1);
	table->number_philo = ft_atoi(argv[1]);
	table->tdie = ft_atoi(argv[2]);
	table->teat = ft_atoi(argv[3]);
	table->tsleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		table->number_eat = ft_atoi(argv[5]);
		if (table->number_eat == 0)
			return (1);
	}
	pthread_mutex_init(&table->print, NULL);
	table->init_program = get_time_in_ms();
	return (0);
}

int	check_arguments(int argc, char **argv, t_table *table)
{
	int	wrong_check;

	wrong_check = 0;
	if (argc < 5 || argc > 6)
	{
		wrong_check = 1;
		return (print_wrong_text(wrong_check));
	}
	if (save_arguments(table, argc, argv))
		return (1);
	if (table->number_philo == 0 || table->number_philo > 200)
		return (1);
	else if (argc == 6 && (table->number_eat < 0))
		wrong_check = 2;
	else if (table->tdie < 60 || table->tdie > RAND_MAX)
		wrong_check = 4;
	else if (table->teat < 60 || table->teat > RAND_MAX)
		wrong_check = 5;
	else if (table->tsleep < 60 || table->tsleep > RAND_MAX)
		wrong_check = 6;
	else
		return (init_philo(table));
	return (print_wrong_text(wrong_check));
}
