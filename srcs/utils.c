/*
** EPITECH PROJECT, 2018
** malloc.h
** File description:
** philosopher
*/

#include "philo.h"

int check_nb(char *str, int way)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (atoi(str) == 0 && way == 1)
		return (1);
	else if ((atoi(str) == 0 || atoi(str) == 1) && way == 2)
		return (1);
	return (0);
}

int check_param(int ac, char **av)
{
	if (ac != 5) {
		error_msg("le nombre d'argument est invalid");
		return (1);
	}
	else if (((strcmp(av[1], "-e") == 0 && strcmp(av[3], "-p") == 0) ||
		(strcmp(av[3], "-e") == 0 && strcmp(av[1], "-p") == 0)) &&
		check_nb(av[2], 1) == 0 && check_nb(av[4], 1) == 0)
		return (0);
	return (1);
}

void take_value(int *philo, int *step, char **av)
{
	if (strcmp(av[1], "-p") == 0 && check_nb(av[2], 2) == 0) {
		*philo = atoi(av[2]);
		*step = atoi(av[4]);
	}
	else if (strcmp(av[1], "-e") == 0 && check_nb(av[4], 2) == 0) {
		*philo = atoi(av[4]);
		*step = atoi(av[2]);
	}
	else
		error_msg("1 seul philosopher :/ .");
}

void error_msg(char *str)
{
	fprintf(stderr, "%s\n", str);
	exit(84);
}

void usage(void)
{
	printf("Usage : ./philo -p [nb of philo] -e [nb of eat]\n");
	exit(0);
}
