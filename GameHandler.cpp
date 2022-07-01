#include "GameHandler.h"
#include "Player.h"
#include "UserInterface.h"
#include <windows.h>

void GameHandler::changePlayerScreen(std::string namePlayer) {

	system("cls");
	system("Color F0");
	std::cout << "Now is time for " << namePlayer << " move."/* \n\nIf you are ready press any button..."*/ << std::endl;
	system("pause");
}

int GameHandler::inputFirstPlayerSettings() {

	std::cout << "\tPlease enter nick for First Player: "; 
	player1.setName();
	system("cls");

	inter.displayCurrentPlayerBoard(player1);
	std::cout << player1.getName() << " podaje swoje statki\n" << std::endl; // pobieramy statki (metoda) od Michała
	
	player1.placeShips(inter);

	return 0;
}

int GameHandler::inputSecondPlayerSettings() {

	system("cls");
	std::cout << "Please enter nick for Second Player: ";
	player2.setName();

	inter.displayCurrentPlayerBoard(player2);
	std::cout << player2.getName() << " podaje swoje statki\n" << std::endl; // pobieramy statki (metoda) od Michała

	player2.placeShips(inter);

	return 0;
}

void GameHandler::firstPlayerMove() {
	system("cls");
	system("Color 30");
	diplayTurnToEnd();
	std::cout << player1.getName() << " wykonuje swoj ruch." << std::endl;

	// wyswietl plansze
	std::cout << std::endl << "Your board:" << std::endl;
	inter.displayCurrentPlayerBoard(player1);
	std::cout << std::endl;
	std::cout << std::endl << "Enemy's board:" << std::endl;
	inter.displayRivalsBoard(player2);
	std::cout << std::endl;

	bool hit;
	// zapytaj uzytkownika o wspolrzedne strzalu 
	// walidacja (nie moga wykraczac poza plansze)
	int x, y;
	inter.askForCoordinates();
	x = inter.getX();
	y = inter.getY();

	// zaznaczenie strzalu w shotsHistory[][]
	player2.shotsHistory[y][x] = true;

	// sprawdz czy trafienie ktoregos z floty
	player2.handleTheShoot(x,y);
}


void GameHandler::secondPlayerMove() {

	system("cls");
	system("Color 03");
	diplayTurnToEnd();
	std::cout << player2.getName() << " wykonuje swoj ruch." << std::endl;

	// wyswietl plansze
	std::cout << std::endl << "Your board:" << std::endl;
	inter.displayCurrentPlayerBoard(player2);
	std::cout << std::endl;
	std::cout << std::endl << "Enemy's board:" << std::endl;
	inter.displayRivalsBoard(player1);
	std::cout << std::endl;

	bool hit;
	// zapytaj uzytkownika o wspolrzedne strzalu 
	// walidacja (nie moga wykraczac poza plansze)
	int x, y;
	inter.askForCoordinates();
	x = inter.getX();
	y = inter.getY();

	// zaznaczenie strzalu w shotsHistory[][]
	player1.shotsHistory[y][x] = true;

	// sprawdz czy trafienie ktoregos z floty
	player1.handleTheShoot(x, y);
}

void GameHandler::getTurnsLimits() {

	while (true) {
		system("cls");
		std::cout << "\tEnter number of wanted turns (3-25) >> ", std::cin >> turnLimit;

		if ((turnLimit >= 3) && (turnLimit <=25))
			break;
		else
			std::cout << "\tInvalid input. Try again!\n" << std::endl;

		system("pause");
	}
}

void GameHandler::diplayTurnToEnd() {
	std::cout << "\nTurns left :" << turnLimit - turnCounter << "\n" << std::endl;
}

void GameHandler::displayWhoWin(std::string winnerPlayerName) {
	std::cout << "\n\t\tThe winner is... " << winnerPlayerName << std::endl;
}

void GameHandler::gameLoop() {

	while (menuChoice != 1) {
		menuChoice = inter.getUserMenuChoice();
		inter.mainMenu(menuChoice);
	}

	getTurnsLimits();
	inputFirstPlayerSettings();
	changePlayerScreen("second player's");
	inputSecondPlayerSettings();

	while (player1.howManyHits < 4 && player2.howManyHits < 4 && turnCounter <= turnLimit) {
		// metody z userInterface od Michała o sprawdzaniu strzałów
		changePlayerScreen(player1.getName());
		firstPlayerMove();
		std::cout << "inkrementacja ruchow: " << player1.howManyHits << std::endl;

		changePlayerScreen(player2.getName());
		secondPlayerMove();
		std::cout << "inkrementacja 2 ruchow: " << player1.howManyHits << std::endl;
		turnCounter++;
	}
	
	inter.displayEndGameSign();
	if ((turnCounter - 1) == turnLimit)
		std::cout << "\n\tNo more turns, it's a draw!" << std::endl;
	else {
		if (player1.howManyHits > player2.howManyHits) {
			displayWhoWin(player2.getName());
		} else {
			displayWhoWin(player1.getName());
		}
	}

	system("pause");
}