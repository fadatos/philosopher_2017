/*
** EPITECH PROJECT, 2018
** malloc.h
** File description:
** philosopher
*/

#include "philo.h"

void try_thread_exit(t_struct philo)
{
	if (philo.nb_eat <= 0 && philo.id % 2 == 0) {
		lphilo_sleep();
		pthread_exit(NULL);
	}
	else if (philo.nb_eat <= 0)
		pthread_exit(NULL);
}

void *choix_action(void *data)
{
	t_struct	*philo;
	int		i;

	philo = data;
	i = philo[0].id;
	philo = philo - i;
	while (42) {
		if (philo[i].etat == 0)
			philo_sleep(philo, i);
		else if (philo[i].etat == 1)
			philo_think(philo, i);
		else
			philo_eat(philo, i);
		try_thread_exit(philo[i]);
	}
	return (NULL);
}

void run_multi_thread(t_struct *philo)
{
	for (int i = 0; i < philo[0].nb_philo; ++i)
		pthread_create(&philo[i].thread, NULL, choix_action, philo + i);
	for (int i = 0; i < philo[0].nb_philo; ++i)
		pthread_join(philo[i].thread, NULL);
	for (int i = 0; i < philo[0].nb_philo; ++i)
		pthread_mutex_destroy(&philo[i].mutex);
	free(philo);
}
