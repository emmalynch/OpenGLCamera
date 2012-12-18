#pragma once
class Camera
{
public:
	Camera(void);
	~Camera(void);
	void updateCam(int x, int y, int z, int xRotation, int yRotation);
	
	void zoom(int amount);
	void moveOnZ(int amount);//move forwards
	void moveOnY(int amount);//move upwards i.e. jump
	void moveOnX(int amount);//strafe
	void rotateUp (int angle);
	void rotateAround(int angle);

	int mX, mY, mZ, mXRotation, mYRotation, mDistanceFromCharacter;
};

