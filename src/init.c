/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:23:08 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/29 13:08:18 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static t_philo	*sit_philos(t_table table)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * table.philo_nbr);
	if (!philos)
		return (NULL);
	while (i < table.philo_nbr)
	{
		philos[i].philo_id = i;
		philos[i].meal_count = 0;
		philos[i].full = false;
		philos[i].last_meal_time = table.start_time;
		philos[i].left_fork = &table.forks[i];
		philos[i].right_fork = &table.forks[(i + 1) % table.philo_nbr];
		philos[i].table = &table;
		i++;
	}
	return (philos);
}

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

static t_table set_table(int argc, char **argv)
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
	return (table);
}

t_table init_sim(int argc, char **argv)
{
	t_table table;

	table = set_table(argc, argv);
	table.forks = place_forks(table.philo_nbr);
	table.philos = sit_philos(table);
	return (table);
}