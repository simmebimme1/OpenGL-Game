#pragma once
#include <string>

class GameObject {

public:
	 GameObject();
	 GameObject(float x, float y, float velX, float velY, std::string ID);

	virtual void tick() = 0;
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual void setX(float x) = 0;
	virtual void setY(float y) = 0;
	virtual void setVelX(float velX) = 0;
	virtual void setVelY(float velY) = 0;
	virtual float getVelX() = 0;
	virtual float getVelY() = 0;
	virtual float getVertex(int i) = 0;
	virtual float getPercievedX();
	virtual void setPercievedX(float x);
	virtual float getPercievedY();
	virtual void setPercievedY(float y);
	virtual float getSize();

	virtual void setID(std::string ID) = 0;
	virtual std::string getID() = 0;
	virtual float* getColor() = 0;

private:

protected:
	float velX, velY, x, y;
	int size;
	std::string ID;
	float colorArray[3];
	float vertex[4];

};

