/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:20:38 by ottouti           #+#    #+#             */
/*   Updated: 2024/02/25 14:49:32 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

long get_time(long start_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - start_time);
}

void check_if_full(t_philo *philo)
{
	if (philo->meal_count == philo->table->meal_max)
		philo->full = true;
}

int check_if_all_full(t_table *table)
{
	int i;
	int full;

	i = 0;
	full = 0;
	while (i < table->philo_nbr)
	{
		if (table->philos[i].full)
			full++;
		i++;
	}
	if (full == table->philo_nbr)
	{
		printf("All philosophers are full\n");
		return (1);
	}
	return (0);
}