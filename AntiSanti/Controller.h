#pragma once
#include "glut.h"
class Controller
{
public:
	Controller(void);
	~Controller(void);
	void mouseController(int x, int y);
	void keyPress(unsigned char key, int x, int y);


};

