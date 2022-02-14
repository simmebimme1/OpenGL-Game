#include "FollowingEnemy.h"
#include <iostream>

FollowingEnemy::FollowingEnemy() {

}

FollowingEnemy::FollowingEnemy(float x, float y, float velX, float velY, GameObject* player) {
	this->x = x;
	this->y = y;
	this->ID = ID;
	this->velX = velX;
	this->velY = velY;
	this->vectorLength = 1.0f;
	this->dirX = 0.0f;
	this->dirY = 0.0f;

	this->size = 10;
	this->colorArray[0] = 0.0f;
	this->colorArray[1] = 1.0f;
	this->colorArray[2] = 0.0f;

	this->vertex[0] = this->x - size;
	this->vertex[1] = this->x + size;
	this->vertex[2] = this->y - size;
	this->vertex[3] = this->y + size;

	this->ID = "FollowingEnemy";

	this->player = player;

}

std::string FollowingEnemy::getID() {
	return this->ID;
}

float* FollowingEnemy::getColor() {
	return this->colorArray;
}

void FollowingEnemy::setID(std::string ID) {
	this->ID = ID;
}


void FollowingEnemy::tick() {

	this->calculateDir();

	this->x += this->velX;
	this->y += this->velY;

	this->vertex[0] = this->x - this->size;
	this->vertex[1] = this->x + this->size;
	this->vertex[2] = this->y - this->size;
	this->vertex[3] = this->y + this->size;

	this->velX -= this->dirX / vectorLength;
	this->velY -= this->dirY / vectorLength;

}

float FollowingEnemy::getX() {
	return this->x;
}
void FollowingEnemy::setX(float x) {
	this->x = x;
}
float FollowingEnemy::getY() {
	return this->y;
}
void FollowingEnemy::setY(float y) {
	this->y = y;
}

void FollowingEnemy::calculateDir() {


	this->dirX = player->getX() - this->x;
	this->dirY = player->getY() - this->y;

	this->vectorLength = sqrt((this->dirX * this->dirX) + (this->dirY * this->dirY));
	this->vectorLength /= 2;
	
	this->velX += (this->dirX / vectorLength);
	this->velY += (this->dirY / vectorLength);

}

void FollowingEnemy::setVelX(float velX) {
	this->velX = velX;
}

void FollowingEnemy::setVelY(float velY) {
	this->velY = velY;
}

float FollowingEnemy::getVelX() {
	return this->velX;
}

float FollowingEnemy::getVelY() {
	return this->velY;
}

float FollowingEnemy::getVertex(int i) {
	return this->vertex[i];
}
