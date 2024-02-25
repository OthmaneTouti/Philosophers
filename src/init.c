/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:46:31 by ottouti           #+#    #+#             */
/*   Updated: 2024/02/25 14:51:44 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void prepare_to_eat(t_philo *philo)
{
	int err;
	if (!philo->full)
	{ 
		err = pthread_create(&philo->thread_id, NULL, &eat, philo);
		if (err != 0)
		{
			printf("Error creating thread\n");
			return;
		}
		printf("%s%ld%s: %d started\n", BLUE,
			get_time(philo->table->start_time), NC, philo->philo_id + 1);
		err = pthread_join(philo->thread_id, NULL);
		if (err != 0)
		{
			printf("Error joining thread\n");
			return;
		}
	}
}

void	init_sim(t_table *table)
{
    int	i;

    i = 0;
	while(table->end == false)
	{
    	while (i < table->philo_nbr)
   	 	{
		
			prepare_to_eat(&table->philos[i]);
			if (check_if_all_full(table))
			{
				table->end = true;
				break ;
			}
        i++;
    	}
	}
}