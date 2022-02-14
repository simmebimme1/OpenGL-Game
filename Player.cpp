#include "Player.h"
#include <iostream>

Player::Player() {

}

Player::Player(float x, float y, float velX, float velY) {
	this->x = x;
	this->y = y;
	this->velX = velX;
	this->velY = velY;
	this->percievedX = x;
	this->percievedY = y;
	this->percievedVelX = 0.0f;
	this->percievedVelY = 0.0f;
	
	this->size = 10;
	this->colorArray[0] = 1.0f;
	this->colorArray[1] = 1.0f;
	this->colorArray[2] = 1.0f;

	this->vertex[0] = this->x - size;
	this->vertex[1] = this->x + size;
	this->vertex[2] = this->y - size;
	this->vertex[3] = this->y + size;
	
	this->ID = "Player";
	


}

std::string Player::getID() {
	return this->ID;
}

float* Player::getColor() {
	return this->colorArray;
}

void Player::setID(std::string ID) {
	this->ID = ID;
}


void Player::tick() {

	this->vertex[0] = this->x - this->size;
	this->vertex[1] = this->x + this->size;
	this->vertex[2] = this->y - this->size;
	this->vertex[3] = this->y + this->size;

	this->percievedX += this->percievedVelX;
	this->percievedY += this->percievedVelY;
}

float Player::getX() {
	return this->x;
}
void Player::setX(float x) {
	this->x = x;
}
float Player::getY() {
	return this->y;
}
void Player::setY(float y) {
	this->y = y;
}

void Player::setVelX(float velX) {
	this->velX = velX;
}

void Player::setVelY(float velY) {
	this->velY = velY;
}

float Player::getVelX() {
	return this->velX;
}

float Player::getVelY() {
	return this->velY;
}

float Player::getVertex(int i) {
	return this->vertex[i];
}

float Player::getPercievedX() {
	return this->percievedVelX;
}

void Player::setPercievedX(float x) {
	this->percievedVelX = x;
}

float Player::getPercievedY() {
	return this->percievedVelY;
}

void Player::setPercievedY(float y) {
	this->percievedVelY = y;
}