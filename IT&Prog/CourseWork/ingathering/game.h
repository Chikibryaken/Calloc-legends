#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class entity {

protected:
	int x_scale, y_scale, width, height;
	int direction, score, healthPoint;
	float x_position, y_position;
	float dx, dy, speed = 0;
	bool life;

	String name;
	String location;
	Texture texture;
	Sprite sprite;

public:
	entity() {}
	entity(String loc, int xScl, int yScl, int posX, int posY, int wid, int hei);
	~entity() {}
};

class basket : public entity {

public:
	basket() {}
	basket(String Name, String loc, int xScl, int yScl, int posX, int posY, int wid, int hei);
	~basket() {}

	void setDirection(int d);
	void setSpeed(float s);
	void setScore(int sc);
	void setHP(int hp);

	int getWidth();
	int getHeight();
	int getScore();
	int getHP();
	float getX();
	float getY();
	Sprite getSprite();

	bool alive();
	void update(float time);
};

class fruit : public entity {

public:
	fruit() {}
	fruit(String loc, int xScl, int yScl, int posX, int posY, int wid, int hei, int point);
	~fruit() {}

	void setX(int x);
	void setY(int y);
	void setSpeed(float s);

	int getWidth();
	int getHeight();
	int getScore();
	float getX();
	float getY();
	Sprite getSprite();

	void update(float time);
};