#include "game.h"

using namespace sf;

entity::entity(String loc, int xScl, int yScl, int posX, int posY, int wid, int hei) {
	location = loc;
	x_scale = xScl; x_position = posX;
	y_scale = yScl; y_position = posY;
	width = wid; height = hei;
	life = true;

	texture.loadFromFile("../harvest/resourses/" + loc);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, width, height));
	sprite.setScale(x_scale, y_scale);
}




basket::basket(String Name, String loc, int xScl, int yScl, int posX, int posY, int wid, int hei) {
	name = Name;
	location = loc;
	x_scale = xScl; x_position = posX;
	y_scale = yScl; y_position = posY;
	width = wid; height = hei;
	direction = 0;
	healthPoint = 5;
	score = 0;
	life = true;

	texture.loadFromFile("../harvest/resourses/" + loc);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, width, height));
	sprite.setScale(x_scale, y_scale);
}


void basket::setDirection(int d) {
	direction = d;
}

void basket::setSpeed(float s) {
	speed = s;
}

void basket::setScore(int sc) {
	score = sc;
}

void basket::setHP(int hp) {
	healthPoint = hp;
}


int basket::getWidth() {
	return width * x_scale;
}

int basket::getHeight() {
	return height * y_scale;
}

int basket::getScore() {
	return score;
}

int basket::getHP() {
	return healthPoint;
}

float basket::getX() {
	return x_position;
}

float basket::getY() {
	return y_position;
}


Sprite basket::getSprite() {
	return sprite;
}

void basket::update(float time) {

	switch (direction) {
	case 0: dx = speed; break;
	case 1: dx = -speed; break;
	}

	x_position += dx * time;

	speed = 0;
	sprite.setPosition(x_position, y_position);
	if (healthPoint < 1) { life = false; }
}

bool basket::alive() {
	return life;
}




fruit::fruit(String loc, int xScl, int yScl, int posX, int posY, int wid, int hei, int point) {
	location = loc;
	x_scale = xScl; x_position = posX;
	y_scale = yScl; y_position = posY;
	width = wid; height = hei;
	direction = 0;
	score = point;

	texture.loadFromFile("../harvest/resourses/" + loc);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, width, height));
	sprite.setScale(x_scale, y_scale);
}

void fruit::setSpeed(float s) {
	speed = s;
}

void fruit::setX(int x) {
	x_position = x;
}

void fruit::setY(int y) {
	y_position = y;
}


int fruit::getWidth() {
	return width * x_scale;
}

int fruit::getHeight() {
	return height * y_scale;
}

int fruit::getScore() {
	return score;
}

float fruit::getX() {
	return x_position;
}

float fruit::getY() {
	return y_position;
}

Sprite fruit::getSprite() {
	return sprite;
}


void fruit::update(float time) {
	switch (direction) {
	case 0: dy = speed; break;
	}

	y_position += dy * time;

	sprite.setPosition(x_position, y_position);
}