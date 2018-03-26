/*
** EPITECH PROJECT, 2018
** malloc.h
** File description:
** philosopher
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "extern.h"

#define PHILO_NEXT(X) (i + X) % philo[i].nb_philo

/* variable etat: 0 DODO, 1 THINK, 2 EAT */

typedef struct		s_struct
{
	int				id;
	int				nb_philo;
	int				nb_eat;
	int				etat;
	pthread_t			thread;
	pthread_mutex_t	mutex;
}t_struct;

/* main.c*/
int	check_param(int ac, char **av);

/* philo.c*/
void unlock_sticks(t_struct *philo, int i);
void try_borrow_sticks(t_struct *philo, int i, int next);
void philo_think(t_struct *philo, int i);
void philo_eat(t_struct *philo, int i);
void philo_sleep(t_struct *philo, int i);

/* thread.c*/
void try_thread_exit(t_struct philo);
void *choix_action(void *data);
void run_multi_thread(t_struct *philo);

/* utils.c*/
int check_nb(char *str, int way);
int check_param(int ac, char **av);
void usage(void);
void error_msg(char *str);
void take_value(int *philo, int *step, char **av);

#endif /* !PHILO_H_ */
