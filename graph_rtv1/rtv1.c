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

	if (vec3dot(rd, &s->vec1) > 0.001) // check that line isn't paralell to plane
	{
		vec3sub(ro, &s->c, &u);
		d = -vec3dot(&u, &s->vec1) / vec3dot(rd, &s->vec1);
		vec3add(&u, vec3scale(rd, &dir, d), &u);
		if (vec3len(&u) < 50)
		{
			hit->d = vec3dot(vec3sub(&s->c, ro, &dir), &s->vec1) / vec3dot(rd, &s->vec1);
			vec3add(ro, vec3scale(rd, &u, hit->d), &hit->u);
			vec3cpy(&s->vec1, &hit->n);
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
	if (d > 0.01)
	{
		hit->d = (-b - sqrt(d)) / (2.0 * a);
		if (hit->d < 0.001 && hit->d < 500.0)
			return (0);
		vec3add(ro, vec3scale(rd, &hit->u, hit->d), &hit->u);
		vec3sub(&hit->u, &s->c, &hit->n);
		vec3scale(&hit->n, &hit->n, 1.0/s->f1);
		return (1);
	}
	return (0);
}

int		vec3_to_color(t_vec3 c)
{
	int		ret;

	ret = 0;
	ret = ((int)(c.x * 255) << 16)
		+ ((int)(c.y * 255) << 8)
		+ ((int)(c.z * 255) << 0);
	return (ret);
}

t_vec3	color_to_vec3(int c)
{
	t_vec3		ret;

	ret.x = (float)((c >> 16) & 0xff) / 255.0;
	ret.y = (float)((c >>  8) & 0xff) / 255.0;
	ret.z = (float)((c >>  0) & 0xff) / 255.0;
	return (ret);
}

int		isect(t_vec3 *ro, t_vec3 *rd, t_shape *scene, t_hit *ret)
{
	int		ir;
	int		i;
	int		j;
	t_hit	curr;

	ret->d = 500000.0;
	ir = 0;
	j = 0;
	while (j < g_env->nshapes)
	{
		i = 0;
		if (scene[j].type == 0)
			i = isectsphere(ro, rd, &scene[j], &curr);
		else if (scene[j].type == 1)
			i = isectplane(ro, rd, &scene[j], &curr);
		if (i && curr.d < ret->d)
		{
			ir = 1;
			ret->d = curr.d;
			ret->shape = &scene[j];
			vec3cpy(&curr.n, &ret->n);
			vec3cpy(&curr.u, &ret->u);
			vec3add(&ret->u, vec3scale(&curr.n, &curr.n, 0.005), &ret->u);
			
		}
		j++;
	}
	return (ir);
}

t_vec3		main_image(float x, float y)
{
	t_hit		isect1;	
	t_hit		isect2;
	t_vec3		ro;
	t_vec3		rd;
	t_vec3		object;
	t_vec3		retcol;

	vec3set(&retcol, 0.0, 0.0, 0.0);
	set_raydir(x, y, g_env->cam);
	if (isect(g_env->cam->ro, g_env->cam->rd, g_env->scene, &isect1))
	{
		vec3set(&object, -45.0, -50.0, 50.0);
		vec3sub(&object, &isect1.u, &rd);
		vec3norm(&rd, &rd);
		vec3fadd(&rd, &rd, rando()*0.5-0.25, rando()*0.5-0.25, rando()*0.5-0.25);
		if (isect(&isect1.u, &rd, g_env->scene, &isect2))
		{
			vec3cpy(&isect1.shape->vec2, &retcol);
			vec3scale(&retcol, &retcol, 0.2);
			return (retcol);
		}
		vec3cpy(&isect1.shape->vec2, &retcol);
		vec3scale(&retcol, &retcol, 0.8 + 0.2 * vec3dot(&isect1.n, &rd));
		return (retcol);
	}
	return (retcol);
}

int		draw(void)
{
	int				i;
	int				x;
	int				y;
	int				s;
	int				sn;

	g += 0.1;
	//g = 1.2;
	sn = 25;
	//vec3set(&g_env->scene[0].c, -5,-1.0-fabs(8*cos(g+0.1)), 0.0);
	//vec3set(&g_env->scene[3].c, 0, -1.0-fabs(8*cos(g+0.3)), 0.0);
	//vec3set(&g_env->scene[4].c, 5, -1.0-fabs(8*cos(g+0.5)), 0.0);
	update_cam(g_env->cam);
	printf("%f %f %f\n", g_env->cam->ro->x, g_env->cam->ro->y, g_env->cam->ro->z);
	srand((unsigned)get_micro_time());
	y = 0;
	while (y < g_env->h)
	{
		//printf("%.2f%%\n\r\r\r", (x+y*600.0)/(400.0*600.0) * 100.0);
		x = 0;
		while (x < g_env->w)
		{
			i = x + (g_env->h - 1 - y) * g_env->w;
			t_vec3 col;
			t_vec3 ret;
			s = 0;	
			vec3set(&col, 0.0, 0.0, 0.0);
			while (s < sn)
			{
				ret = main_image((float)x+rando(), (float)y+rando());
				//ret = main_image((float)x, (float)y);
				vec3add(&col, &ret, &col);
				s++;
			}
			vec3scale(&col, &col, 1.0/sn);
			//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//glDrawPixels(g_env->w, g_env->h, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, g_env->imgdata);
			//glutSwapBuffers();
			//glFlush();
			//glDrawPixels(g_env->w, g_env->h, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, g_env->imgdata);			
			g_env->imgdata[i] = vec3_to_color(col);
			//g_env->imgdata[x + (y) * g_env->w] = vec3_to_color(col);
			x++;
		}
		y++;
	}
	//fwrite((unsigned char *)g_env->imgdata, 1, g_env->w*g_env->h*4, pipeout);
	//if (g > 3.1415)
	//{
	//	fflush(pipeout);
 	//	fclose(pipeout);
 	//	exit(0);
	//}
	return (0);
}

int		main(int argc, char **argv)
{
    //pipeout = popen("ffmpeg -y -f rawvideo -vcodec rawvideo -pix_fmt rgb32 -s 600x400 -r 10 -i - -f mp4 -q:v 5 -an -vcodec mpeg4 output.mp4", "w");
	t_shape		*scene;
	t_cam		*cam;

	g_env = (t_env *)malloc(sizeof(t_env));
	g_env->w = 600;
	g_env->h = 400;
	g_env->imgdata = (int *)malloc(sizeof(int) * g_env->w * g_env->h);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(g_env->w, g_env->h - 1);
	g_env->wd = glutCreateWindow("RTV1");
	glDisable(GL_DEPTH_TEST);
	glutDisplayFunc(draw_loop);
	glutIdleFunc(draw_loop);
	glutKeyboardFunc(keysdown);
	glutKeyboardUpFunc(keysup);
	g_env->pt = get_micro_time();
	/* setup camera */
	init_cam();
	init_scene();
	printf("test\n");
	glutMainLoop();
	if (g_env)
	{
		free(g_env->imgdata);
		free(g_env->cam);
		free(g_env->scene);
		free(g_env);
	}
	exit(0);
}
