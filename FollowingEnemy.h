#pragma once
#include "GameObject.h"

class FollowingEnemy : public GameObject {

public:
	FollowingEnemy();
	FollowingEnemy(float x, float y, float velX, float velY, GameObject* player);

	void tick();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	void setVelX(float velX);
	void setVelY(float velY);
	void calculateDir();
	float getVelX();
	float getVelY();
	float getVertex(int i);

	void setID(std::string ID);
	std::string getID();
	float* getColor();

private:
	GameObject* player;
	float dirX, dirY, vectorLength;
protected:
};

