

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../minilibx/mlx.h"


typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*imgdata;

}				t_env;

#endif