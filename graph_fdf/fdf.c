
#include "fdf.h"
#include <math.h>


float g = 1.0;
float s;
void	*get_mlx(void)
{
	static void *mlx;

	if (!mlx)
		mlx = mlx_init();
	return (mlx);
}
int draw_loop(void *p)
{
	t_env		*env;
	env = (t_env *)p;
	//mlx_clear_window(get_mlx(), env->win);
	expose_hook(p);
	usleep(2000);
	g += 0.01;
	s = sin(g/90.0)*cos(g/100.0)*sin(0.5 + g/110.0)-cos(0.2 + g/120.0);
}

int	expose_hook(void *p)
{
	t_env		*env;
	int			i;
	int			j;
	int			c;
	int *dword;
	int bpp;int sl;int endian;
	printf("creating/retrieving image\n");
	env = (t_env *)p;
	printf("env->img address %p\n", env->img);
	if (!env->img)
		if (!(env->img = mlx_new_image(get_mlx(), 800, 800)))
			exit(0);
	printf("env->img address %p\n", env->img);
	printf("getting image data\n");
	char *data = mlx_get_data_addr(env->img, &bpp, &sl, &endian);
	dword = (int *)data;
	printf("drawing image\n");
	i = 0;
	//g += 1;
	while (i < 800 * 800)
	{
		dword[i] += 0x0f5f0f00 * i / 500;
		i++;
	}
	mlx_put_image_to_window(get_mlx(),env->win,env->img,0,0);
	return (0);
}
int	key_hook(int key,void *p)
{
  printf("Key in Win1 : %d\n",key);
  if (key==0xFF1B)
    exit(0);
}

int	mouse_hook(int button,int x,int y, void *p)
{
	//expose_hook(p);
  printf("Mouse in Win, button %d at %dx%d.\n",button,x,y);
}

int		main(int argc, char **argv)
{

	t_env		*env;
	env = malloc (sizeof(t_env));
	// TODO read map
	//parse_args(&env, argc, char **argv);
	//if (!(env->win = mlx_new_window(mlx, env->width, env->height, "FDF")))
	if (!(env->win = mlx_new_window(get_mlx(), 800, 800, "FDF")))
		exit(0);
	env->img = NULL;
	printf("OK\n");
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_mouse_hook(env->win, mouse_hook, 0);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(get_mlx(), draw_loop, env);
		mlx_loop(get_mlx());
	exit(0);
}