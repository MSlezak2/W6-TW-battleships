#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "UserInterface.h"

class GameHandler
{
public:
	int inputFirstPlayerSettings();
	int inputSecondPlayerSettings();
	void firstPlayerMove();
	void secondPlayerMove();
	void gameLoop();
	void changePlayerScreen(std::string namePlayer);
	void getTurnsLimits();
	void diplayTurnToEnd();
	void displayWhoWin(std::string winnerPlayerName);

private:
	UserInterface inter;
	Player player1;
	Player player2;
	int menuChoice{};
	int turnLimit{};
	int turnCounter{0};
};

/* w playerze dajemy atrybut howManyHits
* w game handlerze
* w hit sprawdzamy po każdym ruchu
* howManyHits = howManyShipsElement
* */