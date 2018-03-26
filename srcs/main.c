/*
** EPITECH PROJECT, 2018
** malloc.h
** File description:
** philosopher
*/

#include "philo.h"

int fill_philo(int nb_philo, int nb_time)
{
	int i = 0;
	t_struct *philo = malloc(sizeof(t_struct) * (nb_philo));

	if (philo == NULL)
		return (0);
	while (i < nb_philo) {
		philo[i].nb_philo = nb_philo;
		philo[i].nb_eat = nb_time;
		philo[i].id = i;
		if (i % 2 == 1)
			philo[i].etat = 0;
		else
			philo[i].etat = 1;
		pthread_mutex_init(&philo[i].mutex, NULL);
		i++;
	}
	run_multi_thread(philo);
	return (0);
}

int main(int ac, char **av)
{
	int	nb_philo = 0;
	int	nb_time = 0;

	if (ac == 1)
		usage();
	else if (check_param(ac, av) == 1 || nb_philo > 1)
		error_msg("valeurs arguments invalid");
	take_value(&nb_philo, &nb_time, av);
	RCFStartup(ac, av);
	fill_philo(nb_philo, nb_time);
	RCFCleanup();
	return (0);
}

