#include <iostream>
#include <sstream>
#include <list>

#include "menu.h"
#include "game.h"
#include "leaders.h"

#include "windows.h"

using namespace sf; using namespace std;

int SCREEN_WIDTH = VideoMode::getDesktopMode().width;
int SCREEN_HEIGHT = VideoMode::getDesktopMode().height;

String nickname = L"Гость";

vector<LeaderboardEntry> leaders = loadLeaderboard("leaders.txt");

void mainMenu(RenderWindow& window);
void game(RenderWindow& window);
void info1(RenderWindow& window);
void info2(RenderWindow& window);
void records(RenderWindow& window);
void change(RenderWindow& window);

int random(int min, int max) {
	return min + rand() % (max - min + 1);
}

int main() {

	RenderWindow window(VideoMode::getDesktopMode(), L"Сбор урожая", Style::Fullscreen);
	window.setMouseCursorVisible(false);

	RectangleShape splash(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture splashTexture;
	splashTexture.loadFromFile("../harvest/resourses/splash.png");
	splash.setTexture(&splashTexture);

	window.clear();
	window.draw(splash);
	window.display();

	Sleep(2000);

	mainMenu(window);

	return 0;
}

void mainMenu(RenderWindow& window) {

	srand(time(nullptr));

	RectangleShape Menu(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture menuTexture;
	menuTexture.loadFromFile("../harvest/resourses/menu.png");
	Menu.setTexture(&menuTexture);

	String name_menu[5]{ L"Старт", L"Об игре", L"Рекорд", L"Игроки", L"Выход" };
	menu mymenu(window, 970, 110, name_menu, 100, 190);
	mymenu.setColorMenu(Color::White, Color::Red);
	mymenu.alignment();

	Font font;
	font.loadFromFile("../harvest/resourses/pixelFont.ttf");

	Text signature("", font, 30);
	signature.setFillColor(Color::White);
	signature.setStyle(Text::Regular);
	signature.setString(L" by Фокин Вячеслав И924Б");
	signature.setPosition(SCREEN_WIDTH - 450, SCREEN_HEIGHT - 40);

	Clock clock;

	while (window.isOpen()) {

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W) { mymenu.moveUp(); }
				if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S) { mymenu.moveDown(); }
				if (event.key.code == Keyboard::R) { window.close(); }
				if (event.key.code == Keyboard::Return) {
					switch (mymenu.getSelected())
					{
					case 0: game(window); break;
					case 1: info1(window); break;
					case 2: records(window); break;
					case 3: change(window); break;
					case 4: window.close(); break;
					}
				}
			}
		}

		window.clear();
		window.draw(Menu);
		mymenu.draw();
		window.draw(signature);
		window.display();
	}
}

void game(RenderWindow& window) {

	fruit* frArr[10];

	bool paused = false, tabbed = false;
	int hard = 0;

	Font fontGame;
	fontGame.loadFromFile("../harvest/resourses/pixelFont.ttf");

	Text lifes("", fontGame, 56);
	lifes.setFillColor(Color::White);
	lifes.setStyle(Text::Bold);
	lifes.setPosition(10, SCREEN_HEIGHT - 70);

	Text scores("", fontGame, 56);
	scores.setFillColor(Color::White);
	scores.setStyle(Text::Bold);
	scores.setPosition(SCREEN_WIDTH - 350, SCREEN_HEIGHT - 130);

	Text sec("", fontGame, 56);
	sec.setFillColor(Color::White);
	sec.setStyle(Text::Bold);
	sec.setPosition(SCREEN_WIDTH - 350, SCREEN_HEIGHT - 70);

	Text name("", fontGame, 56);
	name.setFillColor(Color::White);
	name.setStyle(Text::Bold);
	name.setPosition(10, SCREEN_HEIGHT - 130);

	Text text1 ("", fontGame, 35);
	text1.setFillColor(Color::Black);
	text1.setStyle(Text::Bold);
	text1.setPosition(750, 280);
	text1.setString(L"Space для выбора");

	Text text2("", fontGame, 70);
	text2.setFillColor(Color::White);
	text2.setStyle(Text::Bold);
	text2.setPosition(SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 - 70);
	text2.setString(L"КОНЕЦ ИГРЫ :)");

	Text tab("", fontGame, 40);
	tab.setFillColor(Color::White);
	tab.setStyle(Text::Bold);
	tab.setPosition((SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 70);
	tab.setString(L"Tab для дополнительной информации");

	Text control("", fontGame, 40);
	control.setFillColor(Color::Black);
	control.setStyle(Text::Bold);
	control.setString(L"A/← - влево\nD/→ - вправо\nP - пауза\nR - закрытие игры");
	control.setPosition(10, 10);

	Text rules("", fontGame, 40);
	rules.setFillColor(Color::White);
	rules.setStyle(Text::Bold);
	rules.setString(L"Цель: собрать как можно\nбольше овощей и фруктов,\nперемещая корзинку. Очки\nи жизни убавляются при\nсборе гнилого плода и при\nпропуске спелого. Со\nвременем скорость падения\nувеличивается");
	rules.setPosition(10, 300);

	RectangleShape backGame(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture backTexture;
	backTexture.loadFromFile("../harvest/resourses/game.png");
	backGame.setTexture(&backTexture);

	String pauseMenu[2]{ L"Рестарт", L"Выход в меню" };
	pause pause_menu(window, 550, 350, pauseMenu, 56, 300);
	pause_menu.SetColorMenu(Color::White, Color::Red);

	Clock clock;
	Clock gameTimeClock;

	int gameTime = 0;
	int dopTime = 0;
	float spawnTime = 0;
	float complicate = 0;
	
	frArr[0] = new fruit("cherry.png", 3, 3, 0, -250, 25, 27, 2);
	frArr[1] = new fruit("pepper.png", 5, 5, 0, -250, 20, 27, 3);
	frArr[2] = new fruit("dragon.png", 6, 6, 0, -250, 16, 23, 5);
	frArr[3] = new fruit("grape.png", 5, 5, 0, -250, 26, 26, 10);
	frArr[4] = new fruit("pumpkin.png", 8, 8, 0, -250, 28, 29, 15);
	frArr[5] = new fruit("melon.png", 8, 8, 0, -250, 26, 28, 20);
	frArr[6] = new fruit("bugApple.png", 4, 4, 0, -250, 28, 27, -10);
	frArr[7] = new fruit("rottenTang.png", 5, 5, 0, -250, 24, 24, -20);

	basket igr(nickname, "basket.png", 6, 6, SCREEN_WIDTH / 2 - 177, 2 * SCREEN_HEIGHT / 3, 57, 30);

	while (window.isOpen()) {

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		bool printed = false;
		if (!paused) gameTime = gameTimeClock.getElapsedTime().asSeconds();
		time /= 800;
		spawnTime += time;
		complicate += time;

		Event e_game;

		while (window.pollEvent(e_game)) {

			if (e_game.type == Event::KeyReleased) {

				if (e_game.key.code == Keyboard::P) { paused = !paused; }

				if (e_game.key.code == Keyboard::R) { window.close(); }
				if (e_game.key.code == Keyboard::Tab) { tabbed = !tabbed; }
			}
		}

		if (!paused) {

			if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)) {
				igr.setDirection(1);
				igr.setSpeed(0.7);
			}
			if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) {
				igr.setDirection(0);
				igr.setSpeed(0.7);
			}

			if (complicate >= 7000) {
				hard += 1;
				complicate = 0;
			}
			if (spawnTime >= 3000) {
				int fr = random(0, 7);
				int we = random(1, SCREEN_WIDTH - 190);
				int x, y;

				frArr[fr]->setX(we);
				frArr[fr]->setY(1);
				frArr[fr]->setSpeed(0.3 + (hard * 0.01));

				spawnTime = 0;
			}

			for (int i = 0; i < 8; i++) {

				if (frArr[i]->getY() > igr.getY() + igr.getHeight() && i < 6) {

					int hpoint = igr.getHP();
					igr.setHP(hpoint - 1);

					frArr[i]->setY(-250);
					frArr[i]->setSpeed(0);

					int scorepoint = igr.getScore();
					igr.setScore(scorepoint - 5);
				}
				else if (frArr[i]->getY() > igr.getY() + igr.getHeight() && i > 5) {
					frArr[i]->setY(-250);
					frArr[i]->setSpeed(0);
				}

				if (frArr[i]->getX() >= igr.getX() && frArr[i]->getX() + frArr[i]->getWidth() <= igr.getX() + igr.getWidth() && frArr[i]->getY() + frArr[i]->getHeight() >= igr.getY() + (igr.getHeight() / 2)) {

					int scorepoint = igr.getScore();
					igr.setScore(scorepoint + frArr[i]->getScore());

					frArr[i]->setY(-250);
					frArr[i]->setSpeed(0);
					if (i > 5) {

						int hpoint = igr.getHP();
						igr.setHP(hpoint - 1);
					}
				}

				if (igr.getHP() < 1 && !printed) {
					leaders.emplace_back(nickname, igr.getScore(), gameTime);
					sort(leaders.begin(), leaders.end(), compareEntries);
					if (leaders.size() > 10) { leaders.resize(10); }
					saveLeaderboard(leaders, "leaders.txt");
					printed = true;

					window.clear();
					window.draw(text2);
					window.display();

					Sleep(2000);

					mainMenu(window);
				}
			}

			if (paused) {
				dopTime = gameTimeClock.getElapsedTime().asSeconds();
			}
		}

		if (!paused) {
			for (int i = 0; i < 8; i++) {
				frArr[i]->update(time);
			}

			igr.update(time);
		}
		
		window.clear();
		window.draw(backGame);

		for (int i = 0; i < 8; i++) {
			window.draw(frArr[i]->getSprite());
		}
		window.draw(igr.getSprite());

		if (paused) {

			pause_menu.Draw();
			window.draw(text1);

			Event p;
			while (window.pollEvent(p)) {
				if (p.type == Event::KeyPressed) {
					if (p.key.code == Keyboard::Left || p.key.code == Keyboard::A) { pause_menu.MoveLeft(); break; }
					if (p.key.code == Keyboard::Right || p.key.code == Keyboard::D) { pause_menu.MoveRight(); break;  }
					if (p.key.code == Keyboard::P) { paused = !paused; }
					if (p.key.code == Keyboard::Space) {
						switch (pause_menu.getSelected()) {
						case 0: game(window); break;
						case 1: mainMenu(window); break;
						}
					}
				}
			}
		}

		ostringstream HP, scoreCollect, clocks;

		name.setString(L"Имя: " + nickname);
		window.draw(name);

		HP << igr.getHP();
		lifes.setString(L"Жизни: " + HP.str());
		window.draw(lifes);

		scoreCollect << igr.getScore();
		scores.setString(L"Очки: " + scoreCollect.str());
		window.draw(scores);

		clocks << gameTime - dopTime;
		sec.setString(L"Время: " + clocks.str());
		window.draw(sec);

		window.draw(tab);

		if (tabbed) {
			window.draw(control);
			window.draw(rules);
		}

		window.display();
	}
}

void info1(RenderWindow& window) {

	Font fontInf;
	fontInf.loadFromFile("../harvest/resourses/pixelFont.ttf");

	Text titleContr("", fontInf, 64);
	titleContr.setFillColor(Color::White);
	titleContr.setStyle(Text::Bold);
	titleContr.setString(L"Управление");
	titleContr.setPosition(320, 175);

	Text control("", fontInf, 60);
	control.setFillColor(Color::White);
	control.setStyle(Text::Underlined);
	control.setString(L"A/← - влево         \nD/→ - вправо       \nP - пауза             \nTab - информация\nво время игры     \nR - закрытие       \nигры                     ");
	control.setPosition(250, 290);

	Text titleRules("", fontInf, 64);
	titleRules.setFillColor(Color::White);
	titleRules.setStyle(Text::Bold);
	titleRules.setString(L"Правила игры");
	titleRules.setPosition(1115, 175);

	Text rules("", fontInf, 42);
	rules.setFillColor(Color::White);
	rules.setStyle(Text::Underlined);
	rules.setString(L"Нужно собрать как можно\nбольше овощей и фрук-    \nтов, перемещая корзинку.\nЗа крупные спелые плоды\nначисляется больше оч-   \nков. За мелкие плоды на- \nчиnляется меньше очков. \nОчки и жизни убавляются \nпри сборе гнилого плода  \nи при пропуске спелого    ");
	rules.setPosition(1060, 280);

	Text sign("", fontInf, 30);
	sign.setFillColor(Color::Black);
	sign.setStyle(Text::Bold);
	sign.setString(L"Esc - выход в меню                                                        следующая страница - →/D");
	sign.setPosition(250, 820);

	RectangleShape backInfo(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture backTexture;
	backTexture.loadFromFile("../harvest/resourses/info.png");
	backInfo.setTexture(&backTexture);

	while (window.isOpen()) {
		Event e_info;
		while (window.pollEvent(e_info)) {
			if (e_info.type == Event::KeyReleased) {
				if (e_info.key.code == Keyboard::Escape) {
					mainMenu(window);
				}
				if (e_info.key.code == Keyboard::R) { window.close(); }
				if (e_info.key.code == Keyboard::D || e_info.key.code == Keyboard::Right) { info2(window); }
			}
		}

		window.clear();
		window.draw(backInfo);
		window.draw(titleContr);
		window.draw(control);
		window.draw(titleRules);
		window.draw(rules);
		window.draw(sign);
		window.display();
	}
}

void info2(RenderWindow& window) {

	Font fontInf;
	fontInf.loadFromFile("../harvest/resourses/pixelFont.ttf");

	RectangleShape backInfo(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture backTexture;
	backTexture.loadFromFile("../harvest/resourses/info.png");
	backInfo.setTexture(&backTexture);

	Texture Melon;
	Sprite melon;
	Melon.loadFromFile("../harvest/resourses/melon.png");
	melon.setTexture(Melon);
	melon.setScale(8, 8);
	melon.setPosition(265, 200);

	Texture pump;
	Sprite pumpkin;
	pump.loadFromFile("../harvest/resourses/pumpkin.png");
	pumpkin.setTexture(pump);
	pumpkin.setScale(8, 8);
	pumpkin.setPosition(1100, 190);

	Texture grap;
	Sprite grape;
	grap.loadFromFile("../harvest/resourses/grape.png");
	grape.setTexture(grap);
	grape.setScale(5, 5);
	grape.setPosition(310, 580);

	Texture drFr;
	Sprite dragon;
	drFr.loadFromFile("../harvest/resourses/dragon.png");
	dragon.setTexture(drFr);
	dragon.setScale(6, 6);
	dragon.setPosition(650, 285);

	Texture pep;
	Sprite pepper;
	pep.loadFromFile("../harvest/resourses/pepper.png");
	pepper.setTexture(pep);
	pepper.setScale(5, 5);
	pepper.setPosition(1510, 290);

	Texture cher;
	Sprite cherry;
	cher.loadFromFile("../harvest/resourses/cherry.png");
	cherry.setTexture(cher);
	cherry.setScale(3, 3);
	cherry.setPosition(1520, 640);

	Texture bug;
	Sprite apple;
	bug.loadFromFile("../harvest/resourses/bugApple.png");
	apple.setTexture(bug);
	apple.setScale(4, 4);
	apple.setPosition(650, 600);

	Texture rott;
	Sprite tang;
	rott.loadFromFile("../harvest/resourses/rottenTang.png");
	tang.setTexture(rott);
	tang.setScale(5, 5);
	tang.setPosition(1160, 600);

	Text score1("", fontInf, 50);
	score1.setFillColor(Color::White);
	score1.setStyle(Text::Bold);
	score1.setString(L"20 очков     5 очков               15 очков       3 очка");
	score1.setPosition(250, 430);

	Text score2("", fontInf, 50);
	score2.setFillColor(Color::White);
	score2.setStyle(Text::Bold);
	score2.setString(L"10 очков   -10 очков             -20 очков       2 очка");
	score2.setPosition(250, 720);

	Text sign("", fontInf, 30);
	sign.setFillColor(Color::Black);
	sign.setStyle(Text::Bold);
	sign.setString(L"←/A - предыдущая страница                                                     Esc - выход в меню");
	sign.setPosition(250, 820);

	while (window.isOpen()) {

		Event e_info;
		while (window.pollEvent(e_info)) {
			if (e_info.type == Event::KeyReleased) {
				if (e_info.key.code == Keyboard::Escape) {
					mainMenu(window);
				}
				if (e_info.key.code == Keyboard::R) { window.close(); }
				if (e_info.key.code == Keyboard::A || e_info.key.code == Keyboard::Left) { info1(window); }
			}
		}
		window.clear();
		window.draw(backInfo);
		window.draw(melon);
		window.draw(pumpkin);
		window.draw(grape);
		window.draw(dragon);
		window.draw(pepper);
		window.draw(cherry);
		window.draw(apple);
		window.draw(tang);
		window.draw(score1);
		window.draw(score2);
		window.draw(sign);
		window.display();
	}
}

void records(RenderWindow& window) {

	bool saved = false;

	Font fontRec;
	fontRec.loadFromFile("../harvest/resourses/pixelFont.ttf");

	Text problems("", fontRec, 30);
	problems.setFillColor(Color::Black);
	problems.setStyle(Text::Bold);
	problems.setString(L"Проблемы?\nРазберемся");
	problems.setPosition(1550, 670);

	Text alex("", fontRec, 25);
	alex.setFillColor(Color::Black);
	alex.setStyle(Text::Underlined);
	alex.setString(L"Алексей");
	alex.setRotation(90);

	Text legends("", fontRec, 56);
	legends.setFillColor(Color(249, 166, 2));
	legends.setStyle(Text::Bold);
	legends.setString(L"СПИСОК ЛЕГЕНД");
	legends.setPosition(690, 200);

	Text capyb("", fontRec, 35);
	capyb.setFillColor(Color::Black);
	capyb.setStyle(Text::Bold);
	capyb.setString(L"  WANTED\n\n\n\n\nбесценен");
	capyb.setPosition(230, 520);

	Text rec("", fontRec, 40);
	rec.setFillColor(Color(249, 166, 2));
	rec.setStyle(Text::Bold);

	Text print("", fontRec, 34);
	print.setFillColor(Color::Black);
	print.setStyle(Text::Bold);
	print.setString(L"S - подготовить\nк печати");
	print.setPosition(1450, 190);

	Text NST("", fontRec, 40);
	NST.setFillColor(Color(126, 126, 126));
	NST.setStyle(Text::Bold);
	NST.setString(L"Имя             Очки      Время");
	NST.setPosition(680, 285);

	Text clear("", fontRec, 34);
	clear.setFillColor(Color::Black);
	clear.setStyle(Text::Bold);
	clear.setString(L"C - очистить\nсписок");
	clear.setPosition(1450, 290);

	Text create("", fontRec, 35);
	create.setFillColor(Color::Green);
	create.setStyle(Text::Bold);
	create.setString(L"Файл 'leadersPrint.txt' создан");
	create.setPosition(650, 975);

	Text exit("", fontRec, 34);
	exit.setFillColor(Color::Black);
	exit.setStyle(Text::Bold);
	exit.setString(L"Esc - в меню");
	exit.setPosition(1450, 390);

	RectangleShape backRec(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture backTexture;
	backTexture.loadFromFile("../harvest/resourses/records.png");
	backRec.setTexture(&backTexture);

	RectangleShape capybara(Vector2f(240, 180));
	Texture textureCap;
	textureCap.loadFromFile("../harvest/resourses/capybara.png");
	capybara.setTexture(&textureCap);
	capybara.setPosition(210, 560);

	while (window.isOpen()) {

		window.clear();
		window.draw(backRec);

		Event e_records;
		while (window.pollEvent(e_records)) {
			if (e_records.type == Event::KeyPressed) {
				if (e_records.key.code == Keyboard::Escape) {
					mainMenu(window);
				}
				if (e_records.key.code == Keyboard::R) { window.close(); }
				if (e_records.key.code == Keyboard::S) { 
					saveLeaderboard2(leaders, "leadersPrint.txt");
					saved = true;
				}
				if(e_records.key.code == Keyboard::C) { leaders.clear(); saveLeaderboard(leaders, "leaders.txt"); }
			}
		}

		wostringstream lead;
		for (const auto& entry : leaders) {
			lead << left << setw(15) << entry.name << left << setw(12) << entry.score1 << left << setw(5) << entry.score2 << endl;
		}
		rec.setString(lead.str());
		rec.setPosition(680, 340);

		window.draw(problems);
		alex.setPosition(1660, 830);
		window.draw(alex);
		alex.setPosition(1775, 830);
		window.draw(alex);
		window.draw(legends);
		window.draw(capyb);
		window.draw(rec);
		window.draw(print);
		window.draw(NST);
		window.draw(clear);
		window.draw(exit);
		if (saved) {
			window.draw(create);
		}
		window.draw(capybara);
		window.display();
	}
}

void change(RenderWindow& window) {

	bool nameEnter = false, exit = false;
	nickname = "";

	RectangleShape backChan(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture backTexture;
	backTexture.loadFromFile("../harvest/resourses/change.png");
	backChan.setTexture(&backTexture);

	RectangleShape avatar(Vector2f(320, 360));
	Texture textureAv;
	textureAv.loadFromFile("../harvest/resourses/avatar.png");
	avatar.setTexture(&textureAv);
	avatar.setPosition(160, 330);

	Font fontChan;
	fontChan.loadFromFile("../harvest/resourses/pixelFont.ttf");

	Text voenmeh("", fontChan, 64);
	voenmeh.setFillColor(Color::Black);
	voenmeh.setStyle(Text::Bold);
	voenmeh.setString(L"  ВОЕНМЕХ\nлучше всех");
	voenmeh.setPosition(125, 810);

	Text pass("", fontChan, 64);
	pass.setFillColor(Color::Black);
	pass.setStyle(Text::Bold);
	pass.setString(L"ПАСПОРТ ДИРЕКТОРА ОВОЩЕБАЗЫ");
	pass.setPosition(645, 290);

	Text nick("", fontChan, 56);
	nick.setFillColor(Color(126, 126, 126));
	nick.setStyle(Text::Bold);
	nick.setPosition(680, 450);

	Text enter("", fontChan, 40);
	enter.setFillColor(Color(126, 126, 126));
	enter.setStyle(Text::Bold);
	enter.setString(L"Enter - ввод имени     Esc - в меню");
	enter.setPosition(800, 580);

	while (window.isOpen()) {
		if (exit) break;
		Event e_change;
		while (window.pollEvent(e_change) && nameEnter == false) {
			if (e_change.type == Event::TextEntered) {
				cout << e_change.key.code << endl;
				if ((e_change.text.unicode < 128 || (e_change.text.unicode >= 1040) && e_change.text.unicode <= 1103) && (e_change.text.unicode != 9 && e_change.text.unicode != 27)) {
					if (e_change.text.unicode == 13) { nameEnter = true; break; }
					else if (e_change.text.unicode == 8) {
						if (!nickname.isEmpty()) {
							nickname.erase(nickname.getSize() - 1);
						}
					}
					else {
						if (nickname.getSize() < 11) {
							cout << "ASCII character typed: " << static_cast<char>(e_change.text.unicode) << endl;
							nickname += static_cast<wchar_t>(e_change.text.unicode);
							wcout << nickname.toWideString();
						}
					}
				}
			}
		}

		if (nickname.getSize() > 10) {
			nickname = nickname.substring(0, 10);
		}

		wstringstream name;
		name << nickname.toWideString();
		nick.setString(L"Введите имя: " + name.str());

		window.clear();
		window.draw(backChan);
		window.draw(avatar);
		window.draw(voenmeh);
		window.draw(pass);
		window.draw(nick);
		window.draw(enter);
		window.display();
		if (nameEnter && e_change.text.unicode == 27) exit = true;
	}
	if (exit) { mainMenu(window); }
}