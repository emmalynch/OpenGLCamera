#include "params.h"


Params::Params(void)
{
	white_light[0] = 1.0;
	white_light[1] = 1.0;
	white_light[2] = 1.0;
	white_light[3] = 1.0;

	left_light_position[0] = 10;
	left_light_position[1] = 10;
	left_light_position[2] =  0;
	left_light_position[3] =  1;

	right_light_position[0] = -10;
	right_light_position[1] =  10;
	right_light_position[2] =   0;
	right_light_position[3] =   1;
	
	ambient[0] = 1;
	ambient[1] = 1;
	ambient[2] = 1;

	quad = gluNewQuadric();

	
	fogDensity = 0.00;
	fogColour[0] = 0.5;
	fogColour[1] = 0.5;
	fogColour[2] = 0.5;
	fogColour[3] = 1.0;

}


Params::~Params(void)
{
}
