#pragma once
#include "GameObject.h"

class Bullet : public GameObject {

public:
	Bullet();
	Bullet(float x, float y, float velX, float velY);

	void tick();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	void setVelX(float velX);
	void setVelY(float velY);
	float getVelX();
	float getVelY();
	float getVertex(int i);

	void setID(std::string ID);
	std::string getID();
	float* getColor();

private:

protected:

};