/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:08:44 by mmonika           #+#    #+#             */
/*   Updated: 2025/02/23 13:17:41 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

#define RESET	"\033[0m"
#define BOLDRED	"\033[1m\033[31m"

typedef struct s_philo
{
	int				philo_id;
	int				total_eat;
	time_t			last_eat;
	pthread_t		status_check;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				var1_philonum;
	long			var2_die;
	size_t			var3_eat;
	size_t			var4_sleep;
	int				var5_eatnum;
	time_t			start_time;
	int				death;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	t_philo			*philosophers;
}					t_data;

/* utils */
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
time_t	get_time(void);

/* init */
void	initialize_data(t_data *data, int argc, char *argv[]);

/* action */
int	check_var5_eatnum(t_data *data);
int	check_termination(t_data *data);

#endif