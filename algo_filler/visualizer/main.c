
#ifdef __linux__
# include <GL/gl.h>
# include <GL/glut.h>
# include <GL/glu.h>
#endif

#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#endif

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		r;
int		keys[255] = {0};
int		scale = 4;
int		w;
int		h;
char	map[300][300];
GLint	wd;

void	putv(int x, int y)
{
	float xf;
	float yf;

	yf = (float)y - (h / 2.0f);
	xf = (float)x - (w / 2.0f);
	glVertex2f(xf / w * 2.0f, yf / h * 2.0f);
}

void	readmap(void)
{
	char	buf[w * 3];
	int		i;
	int		j;

	fgets(buf, sizeof(buf), stdin);
	if (buf[0] == '=')
	{
		fgets(buf, sizeof(buf), stdin);
		r = 0;
	}
	else
	{
		i = 0;
		while (i < h)
		{
			fgets(buf, sizeof(buf), stdin);
			j = 0;
			while (j < w)
			{
				if (buf[j + 4] == 'x' || buf[j + 4] == 'X')
					map[h - 1 - i][j] = 'x';
				else if (buf[j + 4] == 'o' || buf[j + 4] == 'O')
					map[h - 1 - i][j] = 'o';
				else
					map[h - 1 - i][j] = ' ';
				j++;
			}
			i++;
		}
	}
}

void	readpiece(void)
{
	char	buf[w * 3];
	int		i;
	int		j;
	int		pw;
	int		ph;

	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "Piece %d %d:\n", &ph, &pw);
	for (; ph > 0; ph--)
		fgets(buf, sizeof(buf), stdin);
	fgets(buf, sizeof(buf), stdin);
	fgets(buf, sizeof(buf), stdin);
	if (buf[1] == 'i')
	{
		sscanf(buf, "Piece %d %d:\n", &ph, &pw);
		for (; ph > 0; ph--)
			fgets(buf, sizeof(buf), stdin);
		fgets(buf, sizeof(buf), stdin);
		fgets(buf, sizeof(buf), stdin);
	}
	readmap();
}

void	display(void)
{
	int				i;
	int				j;

	if (r)
		readpiece();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (map[i][j] == 'x')
				glColor3f(0.2f, 0.2f, 0.8f);
			else if (map[i][j] == 'o')
				glColor3f(0.6f, 0.6f, 0.0f);
			else if (map[i][j] == ' ')
				glColor3f(0.0f, 0.0f, 0.0f);
			putv(j, i);
		}
	}
	glEnd();
	glutSwapBuffers();
	glFlush();
}

int		main(int argc, char *argv[])
{
	int		i;
	char	buf[200];

	r = 1;
	for (i = 0; i < 10; i++)
		fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "Plateau %d %d:\n", &h, &w);
	for (i = 0; i < h; i++)
		fgets(buf, sizeof(buf), stdin);
	fgets(buf, sizeof(buf), stdin);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize((scale * w), (scale * h));
	wd = glutCreateWindow("GUI");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glDisable(GL_POINT_SMOOTH);
	glPointSize(scale * 1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glutMainLoop();
	glutDestroyWindow(wd);
	return (0);
}
