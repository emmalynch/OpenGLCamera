#include "World.h"


World::World(void)
{
}


World::~World(void)
{
}

void World::draw()
{
	//yellow walls, blue floor, red ceiling
	glBegin(GL_QUADS);

	//draw the floor
	glColor3f(0, 0, 0.5f);
	glVertex3f(-200, -25, 200);
	glVertex3f(200, -25, 200);
	glVertex3f(200, -25, -50);
	glVertex3f(-200, -25, -50);
	glEnd();

	//draw the sky
	glBegin(GL_QUADS);
	glColor3f( 0.5f, 0, 0);
	glVertex3f(-200, 100, -50);
	glVertex3f(-200, 100, 200);
	glVertex3f(200, 100, 200);
	glVertex3f(200, 100, -50);

	glEnd();


	//draw the back wall
	
	glBegin(GL_QUADS);
	glColor3f( 0.5f,  0.5f, 0);
	glVertex3f(-200, -25, -50);
	glVertex3f(-200, 100, -50);
	glVertex3f(200, 100, -50);
	glVertex3f(200, -25, -50);

	//draw the left side wall
	glVertex3f(-200, -25, -50);
	glVertex3f(-200, 100, -50);
	glVertex3f(-200, 100, 200);
	glVertex3f(-200, -25, 200);

	//draw the right side wall
	glVertex3f(200, -25, -50);
	glVertex3f(200, 100, -50);
	glVertex3f(200, 100, 200);
	glVertex3f(200, -25, 200);

	//draw the front wall
	glVertex3f(-200, -25, 200);
	glVertex3f(-200, 100, 200);
	glVertex3f(200, 100, 200);
	glVertex3f(200, -25, 200);
	glEnd();


	glPopMatrix();

}