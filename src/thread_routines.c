/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:20:46 by ottouti           #+#    #+#             */
/*   Updated: 2024/02/08 16:54:19 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%s%d%s: %d has taken a fork\n", BLUE, get_time(), NC, philo->philo_id + 1);
	pthread_mutex_lock(philo->right_fork);
	printf("%s%d%s: %d has taken a fork\n", BLUE, get_time(), NC, philo->philo_id + 1);
	printf("%s%d%s: %d is eating\n", BLUE, get_time(), NC, philo->philo_id + 1);
	usleep(philo->table->time_to_eat * 1000);
	philo->last_meal_time = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	//check_if_full(philo);
}