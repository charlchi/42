/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:51 by cmoller           #+#    #+#             */
/*   Updated: 2018/08/09 13:18:22 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

FILE *pipeout;
float g = 0.0;

int		isectplane(t_vec3 *ro, t_vec3 *rd, t_shape *s, t_hit *hit)
{
	float	d;
	t_vec3	u;
	t_vec3	dir;

 	if (vec3dot(rd, &s->vec1) > 0) // check that line isn't paralell to plane
 	{
 		vec3sub(ro, &s->c, &u);
 		d = -vec3dot(&u, &s->vec1) / vec3dot(rd, &s->vec1);
 		vec3add(&u, vec3scale(rd, &dir, d), &u);
 		if (fabs(u.x) < s->f1 && fabs(u.y) < s->f1 && fabs(u.z) < s->f1)
 		{
 			hit->d = vec3dot(vec3sub(&s->c, ro, &dir), &s->vec1) / vec3dot(rd, &s->vec1);
 			vec3cpy(&u, &hit->u);
 			return (1);
 		}
	}
	return (0);
}

int		isectsphere(t_vec3 *ro, t_vec3 *rd, t_shape *s, t_hit *hit)
{
	t_vec3	oc;
	t_vec3	u;
	float	a;
	float	b;
	float	c;
	float	d;

	vec3sub(ro, &(s->c), &oc);
	a = vec3dot(rd, rd);
	b = 2.0 * vec3dot(&oc, rd);
	c = vec3dot(&oc, &oc) - s->f1 * s->f1;
	d = (b * b) - (4 * a * c);
	if (d > 0)
	{
		hit->d = (-b - sqrt(d)) / (2.0 * a);
		vec3add(ro, vec3scale(rd, &u, hit->d), &u);
		vec3sub(&u, &(s->c), &u);
		vec3scale(&u, &(hit->u), 1.0/s->f1);
		return (1);
	}
	return (0);
}

int		vec3_to_color(t_vec3 c)
{
	int		ret;

	ret = 0;
	ret = ((int)(c.x * 255) << 0)
		+ ((int)(c.y * 255) << 8)
		+ ((int)(c.z * 255) << 16);
	return (ret);
}

t_vec3	isect(t_vec3 *ro, t_vec3 *rd, t_shape *scene)
{
	int		hit = 0;
	int j = 0;
	int i = -1;
	t_hit	closest;
	t_hit	current;
	closest.d = 500000.0;

	//printf("%f %f %f\n",scene[0].c.x,scene[0].c.y,(&(scene[0]))->c.z);
	update_cam(env->cam);
	//printf("isect rd %f %f %f\n", rd->x, rd->y, rd->z);
	while (j < env->nshapes)
	{
		//printf("poop\n");
		if (scene[j].type == 0)
			hit = isectsphere(ro, rd, &(scene[j]), &current);
		else if (scene[j].type == 1)
			hit = isectplane(ro, rd, &(scene[j]), &current);
		if (hit && current.d < closest.d)
		{
			i = j;
			closest.d = current.d;
			vec3cpy(&current.u, &closest.u);
		}
		hit = 0;
		j++;
	}
	if (i > -1 && i < env->nshapes)
	{
		vec3norm(&closest.u, &closest.u);
		vec3fadd(&closest.u, &closest.u, 1.0, 1.0, 1.0);
		vec3scale(&closest.u, &closest.u, 0.5);
		return (closest.u);
	}
	//return (0x00000000);
	return ((t_vec3){0.0, 0.0, 0.0});
}

t_vec3		main_image(float x, float y)
{
	t_cam	*cam;
	t_shape	*scene;

	// setup camera
	cam = env->cam;
	scene = env->scene;

	vec3set(env->cam->ro, 10*cos(g/4), -5.0+sin(g), 25.0);
	vec3set(&scene[0].c, 0.0, -fabs(5.0*sin(g)), 0.0);
	vec3set(&scene[1].c, 5.0*sin(g), 0.0, 5.0*cos(g));
	vec3set(&scene[2].c, 2.0*sin(g), 2.0*cos(g), 0.0);
	vec3add(&scene[1].c, &scene[2].c, &scene[2].c);
	//vec3set(&scene[4].c, 0.0, -5.0+5.0*sin(g), -10.0);
	//vec3set(&scene[4].vec1, 0.0, 0.5+0.5*sin(g), -1.0);
	//update_cam(cam);
	set_raydir(x, y, cam);
	// do intersections
	return (isect(cam->ro, cam->rd, scene));
}

int		draw(void)
{
	int				x;
	int				y;
	int  			imgdata[400 * 400];

	g += 0.1;
	y = 0;
	while (y < env->h)
	{
		x = 0;
		while (x < env->w)
		{
			t_vec3 col;
			t_vec3 ret;

			vec3set(&col, 0.0, 0.0, 0.0);

			ret = main_image((float)x, (float)y);
			vec3add(&col, &ret, &col);
			ret = main_image((float)x+0.5, (float)y);
			vec3add(&col, &ret, &col);
			ret = main_image((float)x, (float)y+0.5);
			vec3add(&col, &ret, &col);
			ret = main_image((float)x+0.5, (float)y+0.5);
			vec3add(&col, &ret, &col);
			vec3scale(&col, &col, 0.25);
			//imgdata[x + (env->h - 1 - y) * env->w] = vec3_to_color(col);
			imgdata[x + (y) * env->w] = vec3_to_color(col);
			x++;
		}
		y++;
	}
	//glPixelZoom(2.0, 2.0);
	fwrite((unsigned char *)imgdata, 1, env->w*env->h*4, pipeout);
	if (g > 10.0)
	{
		 fflush(pipeout);
 		fclose(pipeout);
 		exit(0);
	}
	//glDrawPixels(env->w, env->h, GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char *)imgdata);
	return (0);
}

int		main(int argc, char **argv)
{

    pipeout = popen("ffmpeg -y -f rawvideo -vcodec rawvideo -pix_fmt rgb32 -s 400x400 -r 25 -i - -f mp4 -q:v 5 -an -vcodec mpeg4 output.mp4", "w");


	t_shape		*scene;
	t_cam		*cam;

	env = (t_env *)malloc(sizeof(t_env));
	env->w = 400;
	env->h = 400;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(env->w, env->h - 1);
	env->wd = glutCreateWindow("RTV1");
	glDisable(GL_DEPTH_TEST);
	glutDisplayFunc(draw_loop);
	glutIdleFunc(draw_loop);
	glutKeyboardFunc(keysdown);
	glutKeyboardUpFunc(keysup);
	env->pt = get_micro_time();
	/* setup camera */
	env->cam = (t_cam *)malloc(sizeof(t_cam));
	env->cam->ro = vec3new(0.0, -3.0, 25.0);
	env->cam->rd = vec3new(0.0, 0.0, 0.0);
	env->cam->la = vec3new(0.0, 0.0, 0.0);
	env->cam->c = vec3new(0.0, 1.0, 0.0);
	env->cam->u = vec3new(0.0, 1.0, 0.0);
	env->cam->f = vec3new(0.0, 0.0, 0.0);
	env->cam->r = vec3new(0.0, 0.0, 0.0);
	update_cam(env->cam); // setup forward, right vectors
	/* setup scene */
	env->nshapes = 5;
	env->scene = malloc(sizeof(t_shape) * env->nshapes);
	env->scene[0].c = (t_vec3){5.0, -5.0, 2.0};
	env->scene[0].f1 = 1.0;
	env->scene[0].type = 0;
	env->scene[1].c = (t_vec3){1.0, -5.0, 5.0};
	env->scene[1].f1 = 2.0;
	env->scene[1].type = 0;
	env->scene[2].c = (t_vec3){3.0, -5.0, 8.0};
	env->scene[2].f1 = 1.0;
	env->scene[2].type = 0;
	env->scene[3].c = (t_vec3){0.0, 0.0, 0.0};
	env->scene[3].vec1 = (t_vec3){0.0, 1.0, 0.0};
	env->scene[3].f1 = 10.0;
	env->scene[3].type = 1;
	env->scene[4].c = (t_vec3){0.0, -10.0, -10.0};
	env->scene[4].vec1 = (t_vec3){0.0, 0.0, -1.0};
	env->scene[4].f1 = 10.0;
	env->scene[4].type = 1;
	printf("test1\n");
	glutMainLoop();
	if (env)
	{
		free(env);
		free(env->cam);
		free(env->scene);
	}
	exit(0);
}
