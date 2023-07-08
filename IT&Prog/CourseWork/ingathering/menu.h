#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class menu {

public:

	float menu_x, menu_y;
	int step, maxCur, sizeFont, selected;

	Font font;
	Text* mainMenu;

	Color menuColor = Color::White;
	Color menuChoosen = Color::Red;

	RenderWindow& win;

	menu() : menu_x(0), menu_y(0), sizeFont(0), step(0), selected(0), maxCur(0), font(), mainMenu(nullptr), win(*(new RenderWindow)) {};
	menu(RenderWindow& window, float menuX, float menuY, String name[], int sizeFont = 60, int step = 80);
	~menu() {
		delete[] mainMenu;
	}

	void setInitText(Text& text, String str, float xpos, float ypos);
	void setColorMenu(Color menColor, Color chooseColor);
	void draw();
	void moveUp();
	void moveDown();
	void alignment();

	int getSelected() {
		return selected;
	}
};

class pause : public menu {

public:

	float pause_x, pause_y;
	int MaxCur, Step, SizeFont;

	Text* pauseMenu;

	RenderWindow& wind;

	pause(RenderWindow& window, float menuX, float menuY, String name[], int sizeFont, int step);
	~pause() { delete[] pauseMenu; }

	void SetInitText(Text& text, String str, float xpos, float ypos);
	void SetColorMenu(Color menColor, Color chooseColor);
	void Draw();
	void MoveLeft();
	void MoveRight();
};