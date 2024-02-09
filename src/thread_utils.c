/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:20:38 by ottouti           #+#    #+#             */
/*   Updated: 2024/02/09 13:34:52 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

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