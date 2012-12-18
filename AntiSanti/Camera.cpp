#include "Camera.h"


Camera::Camera(void)
{
	int mX, mY, mZ, mXRotation, mYRotation, mDistanceFromCharacter;
	mX = 0;
	mY = 0;
	mZ = 0;
	mXRotation = 0;
	mYRotation = 0;
	mDistanceFromCharacter = -2;

}


Camera::~Camera(void)
{
}

void Camera::updateCam(int x, int y, int z, int xRotation, int yRotation)
{
	mX = x;
	mY = y;
	mZ = z;
	mXRotation = xRotation;
	mYRotation = yRotation;
}

void Camera::zoom(int amount)
{
	mDistanceFromCharacter +=amount;
}

void Camera::moveOnX(int amount)
{
	mX +=amount;
}

void Camera::moveOnY(int amount)
{
	mY += amount;
}

void Camera::moveOnZ(int amount)
{
	mZ += amount;
}

void Camera::rotateAround(int angle)
{
	mYRotation +=angle;
}

void Camera::rotateUp(int angle)
{
	mXRotation +=angle;
}