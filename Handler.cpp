#include "Handler.h"

Handler::Handler() {
	
}

void Handler::addObject(GameObject* object) {
	this->gameObjects.push_back(object);
}

void Handler::removeObject(float i) {
	this->gameObjects.erase(gameObjects.begin() + i);
}

void Handler::tick() {
	for (float i = 0; i < this->gameObjects.size(); i++) {
		this->gameObjects.at(i)->tick();
	}
}

float Handler::size() {
	return this->gameObjects.size();
}

GameObject* Handler::getObject(float i) {
	return this->gameObjects.at(i);
}