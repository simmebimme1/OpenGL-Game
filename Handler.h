#pragma once
#include <vector>
#include "GameObject.h"

class Handler {

public:

	Handler();

	GameObject* getObject(int i);
	void addObject(GameObject* object);
	void removeObject(int i);
	void tick();
	int size();


private:
	std::vector<GameObject*> gameObjects;
};

