#pragma once
#include "GL/glut.h"
#include "time.h"

class Params
{
public:
	Params(void);
	~Params(void);

	clock_t			start, finish, t, tickCount;

	GLfloat			white_light[4]; 
	GLfloat			left_light_position[4];
	GLfloat			right_light_position[4];
	GLfloat			ambient[3];

	GLUquadricObj	*quad;

	// variables for the fog
	GLfloat			fogDensity;
	GLfloat			fogColour[4];
};

