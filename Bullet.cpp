#include "Bullet.h"
Bullet::Bullet() {

}

Bullet::Bullet(float x, float y, float velX, float velY) {
	this->x = x;
	this->y = y;
	this->velX = velX;
	this->velY = velY;
	this->ID = "Bullet";

	this->size = 2;
	this->colorArray[0] = 1.0f;
	this->colorArray[1] = 0.5f;
	this->colorArray[2] = 0.5f;

	this->vertex[0] = this->x - size;
	this->vertex[1] = this->x + size;
	this->vertex[2] = this->y - size;
	this->vertex[3] = this->y + size;
}

std::string Bullet::getID() {
	return this->ID;
}

float* Bullet::getColor() {
	return this->colorArray;
}

void Bullet::setID(std::string ID) {
	this->ID = ID;
}


void Bullet::tick() {

	this->vertex[0] = this->x - this->size;
	this->vertex[1] = this->x + this->size;
	this->vertex[2] = this->y - this->size;
	this->vertex[3] = this->y + this->size;

	this->x += this->velX;
	this->y += this->velY;
}

float Bullet::getX() {
	return this->x;
}
void Bullet::setX(float x) {
	this->x = x;
}
float Bullet::getY() {
	return this->y;
}
void Bullet::setY(float y) {
	this->y = y;
}

void Bullet::setVelX(float velX) {
	this->velX = velX;
}

void Bullet::setVelY(float velY) {
	this->velY = velY;
}

float Bullet::getVelX() {
	return this->velX;
}

float Bullet::getVelY() {
	return this->velY;
}

float Bullet::getVertex(int i) {
	return this->vertex[i];
}