#include "BasicEnemy.h"
#include <iostream>

BasicEnemy::BasicEnemy() {

}

BasicEnemy::BasicEnemy(float x, float y, float velX, float velY) {
	this->x = x;
	this->y = y;
	this->ID = ID;
	this->velX = velX;
	this->velY = velY;

	this->size = 20;
	this->colorArray[0] = 1.0f;
	this->colorArray[1] = 0.0f;
	this->colorArray[2] = 0.0f;

	this->vertex[0] = this->x - size;
	this->vertex[1] = this->x + size;
	this->vertex[2] = this->y - size;
	this->vertex[3] = this->y + size;

	this->ID = "BasicEnemy";



}

std::string BasicEnemy::getID() {
	return this->ID;
}

float* BasicEnemy::getColor() {
	return this->colorArray;
}

void BasicEnemy::setID(std::string ID) {
	this->ID = ID;
}


void BasicEnemy::tick() {

	this->x += this->velX;
	this->y += this->velY;

	this->vertex[0] = this->x - this->size;
	this->vertex[1] = this->x + this->size;
	this->vertex[2] = this->y - this->size;
	this->vertex[3] = this->y + this->size;

}

float BasicEnemy::getX() {
	return this->x;
}
void BasicEnemy::setX(float x) {
	this->x = x;
}
float BasicEnemy::getY() {
	return this->y;
}
void BasicEnemy::setY(float y) {
	this->y = y;
}

void BasicEnemy::setVelX(float velX) {
	this->velX = velX;
}

void BasicEnemy::setVelY(float velY) {
	this->velY = velY;
}

float BasicEnemy::getVelX() {
	return this->velX;
}

float BasicEnemy::getVelY() {
	return this->velY;
}

float BasicEnemy::getVertex(int i) {
	return this->vertex[i];
}

float BasicEnemy::getSize() {
	return this->size;
}
