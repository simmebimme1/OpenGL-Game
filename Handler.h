#pragma once
#include <vector>
#include "GameObject.h"

class Handler {

public:

	Handler();

	GameObject* getObject(float i);
	void addObject(GameObject* object);
	void removeObject(float i);
	void tick();
	float size();


private:
	std::vector<GameObject*> gameObjects;
};

