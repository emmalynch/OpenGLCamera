/**********************************************
*	Basic OpenGL application
*	Contains a camera and world 
*
*	Emma Louise Lynch December 2012
	lynche4@gmail.com
***********************************************/



#include "windows.h"
#include <iostream>
#include <stdlib.h>
#include "GL/glut.h"
#include "math.h"
#include "params.h"
#include "World.h"


Params mParams;
World world;
//camera variables
float			xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0;
float			distance = 20.0f; // our radius distance from our character
float			lastx, lasty; // to store the previous coordinates of the mouse
bool			wireframe;

/**
 * Initialize necessary variables
 */
void initialize()
{
	mParams.start = clock();//get the current time
	//lighting
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_POSITION, mParams.right_light_position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, mParams.ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mParams.white_light);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, mParams.ambient);
	glShadeModel(GL_SMOOTH);


}

void enable()
{
	//fog stuff
	glEnable(GL_FOG);
	glFogi (GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2
	glFogfv (GL_FOG_COLOR, mParams.fogColour); //set the fog color
	glFogf (GL_FOG_DENSITY, mParams.fogDensity); //set the density
	glHint (GL_FOG_HINT, GL_NICEST); // set the fog to look the	nicest	
	glFogf(GL_FOG_START, 1.0f);				// Fog Start Depth
	glFogf(GL_FOG_END, 5.0f);				// Fog End Depth
	
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT1); //enable LIGHT0, our Diffuse Light
    glEnable (GL_COLOR_MATERIAL);
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
}

void display(void)
{
	//limit framerate to 60fps
	while(clock()-mParams.tickCount<16){
		mParams.tickCount=clock();
	}

	//necessary housecleaning
	glClearColor (0,0.0,0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	//clear the color buffer and the depth buffer
    enable();

    glLoadIdentity(); 

	glTranslatef(0.0f, 0.0f, -distance); // translate the camera to behind the character, giving a third person view
    glRotatef(xrot,1.0,0.0,0.0); // rotate the camera on the x-axis

	glEnable(GL_COLOR);
	//draw character
	glColor3f(0, 0, 0);
	glutSolidSphere(0.2, 30, 30);

	glDisable(GL_COLOR);

	
    glRotatef(yrot+10,0.0,1.0,0.0);  //rotate the camera on the y-axis 
    glTranslated(-xpos,-4,-zpos); //translate the screen to the position of our camera
	

	world.draw();

	glutSwapBuffers(); //swap the buffers
	glutPostRedisplay();
}



/*
 * Resizes the window and viewport
 */
void reshape (int w, int h) 
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection
	
    glLoadIdentity ();
    gluPerspective (70, (GLfloat)w / (GLfloat)h, 0.1, 1000.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
	
}

void keypress (unsigned char key, int x, int y) 
{
	float xrotrad, yrotrad;

	if (key == 'p'){//go into wireframe
		wireframe=!wireframe;
		if(wireframe){
			
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		
	}
	//rotate the camera upwards
    if (key=='q')
    {
		if (xrot < 40) {
			xrot += 10;
		}
	}
	//rotate the camera downwards
    if (key=='z')
    {
		if (xrot >=10){

			if (xrot <= 40) {
					xrot -= 10;
			}
		}
    }
	//move forwards
    if (key=='w')
    {
	
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f); 
		
			
		xpos += float(sin(yrotrad));	
		zpos -= float(cos(yrotrad));
		ypos -= float(sin(xrotrad))*2;
	}
    //move backwards
    if (key=='s')
    {
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f); 
		
		xpos -= float(sin(yrotrad));
		zpos += float(cos(yrotrad));
		ypos -= float(sin(xrotrad))*2;
	
    }
	//if strafe left - no collision detection here, used for debugging
    if (key=='d')
    {
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos += float(cos(yrotrad)) * 1.5;
		zpos += float(sin(yrotrad)) * 1.5;
    }
	//if strafe right - no collision detection here, used for debugging
    if (key=='a')
    {
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos -= float(cos(yrotrad));
		zpos -= float(sin(yrotrad));
    }
	// if esc is pressed, close the window
    if (key==27)
    {
		exit(0);
    }
	
	//for debugging
	if (key == 'b'){//get position
				
		std::cout << "X position is: "<< xpos << std::endl;
		std::cout << "Y position is: "<< ypos << std::endl;
		std::cout << "Z position is: "<< zpos << std::endl;
	}
}

void mouseControl(int x, int y)
{ 
	int diffx=x-lastx; //check current x against previous x
    lastx=x; 
    lasty=y; 
    xrot + 1; 
    yrot += (float) diffx;    //set the xrot to yrot with the addition of the difference in the x position
}

int main (int argc, char **argv) {

    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH); 
    glutInitWindowSize (1280, 800); //fullscreen
    glutCreateWindow ("OpenGL Basic App"); 
    initialize(); 

    glutDisplayFunc (display); 
    glutIdleFunc (display); 
    glutReshapeFunc (reshape);
    glutPassiveMotionFunc(mouseControl); //check for mouse movement
    glutKeyboardFunc (keypress); 
    glutMainLoop (); 

	return 0;
}