/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:23:08 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/29 13:02:56 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static t_fork	*place_forks(int philo_nbr)
{
	t_fork	*forks;
	int		i;

	i = 0;
	forks = malloc(sizeof(t_fork) * philo_nbr);
	if (!forks)
		return (NULL);
	while (i < philo_nbr)
	{
		forks[i].fork_id = i;
		pthread_mutex_init(&forks[i].fork, NULL);
		i++;
	}
	return (forks);
}
static long get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_table set_table(int argc, char **argv)
{
	t_table	table;
	
	table.philo_nbr = ft_atoi(argv[1]);
	table.time_to_die = ft_atoi(argv[2]);
	table.time_to_eat = ft_atoi(argv[3]);
	table.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table.meal_max = ft_atoi(argv[5]);
	else
		table.meal_max = -1;
	table.start_time = get_time();
	table.end = false;
	table.forks = place_forks(table.philo_nbr);
	if (!table.forks)
		return (table);
	return (table);
}