#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {

}

GameObject::GameObject(float x, float y, float velX, float velY, std::string ID) {
	this->x = x;
	this->y = y;
	this->ID = ID;
	this->velX = velX;
	this->velY = velY;

	this->vertex[0] = this->x - 10;
	this->vertex[1] = this->x + 10;
	this->vertex[2] = this->y - 10;
	this->vertex[3] = this->y + 10;


}

std::string GameObject::getID() {
	return this->ID;
}

float* GameObject::getColor() {
	return this->colorArray;
}

void GameObject::setID(std::string ID) {
	this->ID = ID;
}


void GameObject::tick() {

	this->x += this->velX;
	this->y += this->velY;
	

}

float GameObject::getX() {
	return this->x;
}
void GameObject::setX(float x) {
	this->x = x;
}
float GameObject::getY() {
	return this->y;
}
void GameObject::setY(float y) {
	this->y = y;
}

void GameObject::setVelX(float velX) {
	this->velX = velX;
}

void GameObject::setVelY(float velY) {
	this->velY = velY;
}

float GameObject::getVelX() {
	return this->velX;
}

float GameObject::getVelY() {
	return this->velY;
}

float GameObject::getVertex(int i) {
	return this->vertex[i];
}

float GameObject::getPercievedX() {
	return 1.0f;
}

void GameObject::setPercievedX(float x) {
	
}

float GameObject::getPercievedY() {
	return 1.0f;
}

void GameObject::setPercievedY(float y) {
	
}