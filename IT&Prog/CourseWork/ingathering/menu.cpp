#include "menu.h"

void menu::setInitText(Text& text, String str, float xpos, float ypos) {
	text.setFont(font);
	text.setFillColor(menuColor);
	text.setString(str);
	text.setCharacterSize(sizeFont);
	text.setPosition(xpos, ypos);
}

menu::menu(RenderWindow& window, float menuX, float menuY, String name[], int sizeFont, int step)
		:win(window), menu_x(menuX), menu_y(menuY), sizeFont(sizeFont), step(step) {
	font.loadFromFile("../harvest/resourses/pixelFont.ttf");
	maxCur = name->getSize();
	mainMenu = new Text[maxCur];

	for (int i = 0, ypos = menuY; i < maxCur; i++, ypos += step) {
		setInitText(mainMenu[i], name[i], menuX, ypos);
	}
	selected = 0;
	mainMenu[selected].setFillColor(Color::White);
}

void menu::moveUp() {
	selected--;
	if (selected >= 0) {
		mainMenu[selected].setFillColor(menuChoosen);
		mainMenu[selected + 1].setFillColor(menuColor);
	}
	else {
		mainMenu[0].setFillColor(menuColor);
		selected = maxCur - 1;
		mainMenu[selected].setFillColor(menuChoosen);
	}
}

void menu::moveDown() {
	selected++;
	if (selected < maxCur) {
		mainMenu[selected - 1].setFillColor(menuColor);
		mainMenu[selected].setFillColor(menuChoosen);
	}
	else {
		mainMenu[maxCur - 1].setFillColor(menuColor);
		selected = 0;
		mainMenu[selected].setFillColor(menuChoosen);
	}
}

void menu::alignment() {
	float nullx = 0;
	for (int i = 0; i < maxCur; i++) {
		nullx = mainMenu[i].getLocalBounds().width / 2;

		mainMenu[i].setPosition(mainMenu[i].getPosition().x - nullx, mainMenu[i].getPosition().y);
	}
}

void menu::draw() {
	for (int i = 0; i < maxCur; i++) {
		win.draw(mainMenu[i]);
	}
}

void menu::setColorMenu(Color menColor, Color chooseColor) {
	menuColor = menColor;
	menuChoosen = chooseColor;

	for (int i = 0; i < maxCur; i++) {
		mainMenu[i].setFillColor(menuColor);
	}

	mainMenu[selected].setFillColor(menuChoosen);
}

pause::pause(RenderWindow& window, float menuX, float menuY, String name[], int sizeFont, int step) 
		:wind(window), pause_x(menuX), pause_y(menuY), SizeFont(sizeFont), Step(step), pauseMenu(nullptr) {
	font.loadFromFile("../harvest/resourses/pixelFont.ttf");
	MaxCur = name->getSize();
	pauseMenu = new Text[MaxCur];

	for (int i = 0, xpos = pause_x; i < 2; i++, xpos += Step) {
		SetInitText(pauseMenu[i], name[i], xpos, pause_y);
	}
	selected = 0;
	pauseMenu[selected].setFillColor(Color::White);
}

void pause::MoveLeft() {
	selected--;
	if (selected >= 0) {
		pauseMenu[selected].setFillColor(menuChoosen);
		pauseMenu[selected + 1].setFillColor(menuColor);
	}
	else {
		pauseMenu[0].setFillColor(menuColor);
		selected = 1;
		pauseMenu[selected].setFillColor(menuChoosen);
	}
}

void pause::MoveRight() {
	selected++;
	if (selected < 2) {
		pauseMenu[selected - 1].setFillColor(menuColor);
		pauseMenu[selected].setFillColor(menuChoosen);
	}
	else {
		pauseMenu[1].setFillColor(menuColor);
		selected = 0;
		pauseMenu[selected].setFillColor(menuChoosen);
	}
}

void pause::SetInitText(Text& text, String str, float xpos, float ypos)
{
	text.setFont(font);
	text.setFillColor(menuColor);
	text.setString(str);
	text.setCharacterSize(SizeFont);
	text.setPosition(xpos, ypos);
}

void pause::Draw() {
	for (int i = 0; i < 2; i++) {
		wind.draw(pauseMenu[i]);
	}
}

void pause::SetColorMenu(Color menColor, Color chooseColor) {
	menuColor = menColor;
	menuChoosen = chooseColor;

	for (int i = 0; i < 2; i++) {
		pauseMenu[i].setFillColor(menuColor);
	}

	pauseMenu[selected].setFillColor(menuChoosen);
}