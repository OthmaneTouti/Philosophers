/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:56:12 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/29 12:42:18 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/philo.h"

int	main(int argc, char **argv)
{
	t_table table;
	
	if (argc < 5 || argc > 6)
	{
		printf("Error: Number of arguments invalid\n");
		return (1);
	}
	table = set_table(argc, argv);
	printf("Number of Philosophers: %ld\n"
		"Time to die: %ld\n"
		"Time to eat: %ld\n"
		"Time to sleep: %ld\n"
		"Max meals: %ld\n"
		"Start time: %ld\n", table.philo_nbr, table.time_to_die,
		table.time_to_eat, table.time_to_sleep, table.meal_max,
		table.start_time);
	return (0);
}