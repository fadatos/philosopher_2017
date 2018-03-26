/*
** EPITECH PROJECT, 2018
** malloc.h
** File description:
** philosopher
*/

#include "philo.h"

void unlock_sticks(t_struct *philo, int i)
{
	lphilo_release_chopstick(&philo[i].mutex);
	pthread_mutex_unlock(&philo[i].mutex);
}

void try_borrow_sticks(t_struct *philo, int i, int next)
{
	if (pthread_mutex_trylock(&philo[next].mutex) == 0) {
		lphilo_take_chopstick(&philo[next].mutex);
		lphilo_eat();
		philo[i].nb_eat = philo[i].nb_eat - 1;
		unlock_sticks(philo, next);
		philo[i].etat = 0;
	}
}

void philo_sleep(t_struct *philo, int i)
{
	philo[i].etat = 0;
	lphilo_sleep();
	philo[i].etat = 1;
}

void philo_think(t_struct *philo, int i)
{
	philo[i].etat = 1;
	if (pthread_mutex_trylock(&philo[i].mutex) == 0) {
		lphilo_take_chopstick(&philo[i].mutex);
		lphilo_think();
		unlock_sticks(philo, i);
		philo[i].etat = 2;
	}
}

void philo_eat(t_struct *philo, int i)
{
	int next;

	philo[i].etat = 2;
	next = PHILO_NEXT(1);
	if (pthread_mutex_trylock(&philo[i].mutex) == 0) {
		lphilo_take_chopstick(&philo[i].mutex);
		try_borrow_sticks(philo, i, next);
		unlock_sticks(philo, i);
	}
}
