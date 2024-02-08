/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:46:31 by ottouti           #+#    #+#             */
/*   Updated: 2024/02/08 17:51:03 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	init_sim(t_table *table)
{
    int	i;
    int	err;

    i = 0;
    while (i < table->philo_nbr)
    {
        err = pthread_create(&table->philos[i].thread_id, NULL, &eat, &table->philos[i]);
        if (err != 0)
        {
            printf("Error creating thread\n");
            return;
        }
        printf("%s%ld%s: %d started\n", BLUE, get_time() - table->start_time, NC, table->philos[i].philo_id + 1);
        
        err = pthread_join(table->philos[i].thread_id, NULL);
        if (err != 0)
        {
            printf("Error joining thread\n");
            return;
        }
        i++;
    }
}