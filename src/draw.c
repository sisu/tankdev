#include <GL/gl.h>
#include <GL/glu.h>
#include "game.h"

void drawArea();

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0, 0, -2);
	glScalef(2./areaW, 2./areaH, 0.1);
	glTranslatef(-areaW/2, -areaH/2, 0);

	drawArea();
}

const float quadV[4][2] = {
	{0,0},
	{1,0},
	{1,1},
	{0,1}
};

void drawBox(int x, int y)
{
	for(int i=0; i<4; ++i)
		glVertex3f(x+quadV[i][0], y, quadV[i][1]);
	for(int i=0; i<4; ++i)
		glVertex3f(x+1-quadV[i][0], y+1, quadV[i][1]);
	for(int i=0; i<4; ++i)
		glVertex3f(x, y+1-quadV[i][0], quadV[i][1]);
	for(int i=0; i<4; ++i)
		glVertex3f(x+1, y+quadV[i][0], quadV[i][1]);
	for(int i=0; i<4; ++i)
		glVertex3f(x+quadV[i][0], y+quadV[i][1], 1);
}
/*
void drawGround(int x, int y)
{
	glColor3f(0,.7,0);
	for(int i=0; i<4; ++i) {
}*/

void drawArea()
{
	glColor3f(0,.7,.0);
	glBegin(GL_QUADS);
	for(int i=0; i<4; ++i)
		glVertex2f(areaW*quadV[i][0], areaH*quadV[i][1]);
	glEnd();

	glColor3f(.7,.7,.1);
	glBegin(GL_QUADS);
	for(int i=0; i<areaH; ++i) {
		for(int j=0; j<areaW; ++j) {
			if (tiles[i*areaW+j])
				drawBox(j,i);
//			else 
//				drawGround(j,i);
		}
	}
	glEnd();
}

void initGL()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(60, 4./3., .1, 100);
	glMatrixMode(GL_MODELVIEW);
}
