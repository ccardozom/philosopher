/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:26:31 by ccardozo          #+#    #+#             */
/*   Updated: 2021/07/08 01:47:45 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosopher.h"

// int		init_philo(t_base *base)
// {
// 	int		i;

// 	i = -1;
// 	if (!(base->philo = malloc(sizeof(t_base) * base->nb_ph)) ||
// 	!(base->fork = malloc(sizeof(pthread_mutex_t) * base->nb_ph)))
// 		return (2);
// 	while (++i < base->nb_ph)
// 	{
// 		base->philo[i].nb = i;
// 		base->philo[i].tour = 0;
// 		base->philo[i].frk_l = i;
// 		base->philo[i].frk_r = (i + 1) % base->nb_ph;
// 		//printf("Tenedor de la izquierda: %d  tenedor de la derecha: %d\n",base->philo[i].frk_l = i, base->philo[i].frk_r = (i + 1) % base->nb_ph);
// 		if (pthread_mutex_init(&base->philo[i].t_leat, NULL))
// 			return (3);
// 		base->philo[i].base = base;
// 		//printf("base: %d", );
// 		if (pthread_mutex_init(&base->fork[i], NULL))
// 			return (3);
// 	}
// 	if (pthread_mutex_init(&base->text, NULL))
// 		return (3);
// 	return (0);
// }

int		main(int argc, char **argv)
{
	t_base		base;
	int			i;

	memset(&base, 0, sizeof(t_base));
	if ((i = check_arguments(argc, argv, &base)))
		return (0); //exit_error(&base, i)
	// if ((i = init_thread(&base)))
	// 	return (exit_error(&base, 3));
	// clean_ph(&base);
	return (0);
}
