#include "Handler.h"

Handler::Handler() {
	
}

void Handler::addObject(GameObject* object) {
	this->gameObjects.push_back(object);
}

void Handler::removeObject(int i) {
	this->gameObjects.erase(gameObjects.begin() + i);
}

void Handler::tick() {
	for (int i = 0; i < this->gameObjects.size(); i++) {
		this->gameObjects.at(i)->tick();
	}
}

int Handler::size() {
	return this->gameObjects.size();
}

GameObject* Handler::getObject(int i) {
	return this->gameObjects.at(i);
}