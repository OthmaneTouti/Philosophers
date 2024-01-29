/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:22:34 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/29 13:26:08 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void cleaning(t_table *table)
{
	int i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		printf("Fork %d destroyed\n", i);
		i++;
	}
	free(table->forks);
	printf("Forks freed\n");
	free(table->philos);
	printf("Philosophers freed\n");
}