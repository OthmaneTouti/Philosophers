/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:56:12 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/29 13:10:45 by ottouti          ###   ########.fr       */
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
	table = init_sim(argc, argv);
	// printf("Number of Philosophers: %ld\n"
	// 	"Time to die: %ld\n"
	// 	"Time to eat: %ld\n"
	// 	"Time to sleep: %ld\n"
	// 	"Max meals: %ld\n"
	// 	"Start time: %ld\n", table.philo_nbr, table.time_to_die,
	// 	table.time_to_eat, table.time_to_sleep, table.meal_max,
	// 	table.start_time);
	for (int i = 0; i < table.philo_nbr; i++)
	{
		printf("Philosopher: %d\n"
			"Meal count: %ld\n"
			"Full: %d\n"
			"Last meal time: %ld\n"
			"Left fork: %d\n"
			"Right fork: %d\n", table.philos[i].philo_id, table.philos[i].meal_count,
			table.philos[i].full, table.philos[i].last_meal_time,
			table.philos[i].left_fork->fork_id, table.philos[i].right_fork->fork_id);
	}
	return (0);
}