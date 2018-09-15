/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:30:58 by mgerber           #+#    #+#             */
/*   Updated: 2018/09/11 13:29:51 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_env	arena;

	arena = malloc(sizeof(t_env));
	arena.numplayers = ac - 1;
}

int	loadplayer(int player, char *file, t_env *env)
{
	int index;
	int	i;
	int r;
	int fd;

	index = MEM_SIZE / env->numplayers * player;
	i = 0;
	fd = open(file, O_RDONLY);
	while (r > 0 && i < PROG_NAME_LENGTH)
		r = read(fd, &env->players[player].name[i++], 1);
	i = 0;
	while (r > 0 && i < COMMENT_LENGTH)
		r = read(fd, &env->players[player].comment[i++], 1);
	i = 0;
	while (r > 0 && i < CHAMP_MAX_SIZE)
		r = read(fd, &env->vm[index + i++], 1);
}