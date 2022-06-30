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

	std::cout << "Please enter nick for First Player: "; 
	player1.setName();

	ui.displayCurrentPlayerBoard(player1);

	std::cout << player1.getName() << " podaje swoje statki\n" << std::endl; // pobieramy statki (metoda) od Michała
	
	player1.placeShips(ui);
	//ui.displayCurrentPlayerBoard(player1);

	return 0;
}

int GameHandler::inputSecondPlayerSettings() {

	system("cls");
	std::cout << "Please enter nick for Second Player: ";
	player2.setName();

	ui.displayCurrentPlayerBoard(player2);

	std::cout << player2.getName() << " podaje swoje statki\n\n" << std::endl; // pobieramy statki (metoda) od Michała

	player2.placeShips(ui);
	//ui.displayCurrentPlayerBoard(player2);

	return 0;
}

void GameHandler::firstPlayerMove() {
	system("cls");
	system("Color 30");
	diplayTurnToEnd();
	std::cout << player1.getName() << " wykonuje swoj ruch." << std::endl;

	// wyswietl plansze
	ui.displayCurrentPlayerBoard(player1);
	std::cout << std::endl;
	ui.displayRivalsBoard(player2);
	std::cout << std::endl;

	bool hit;
	// zapytaj uzytkownika o wspolrzedne strzalu 
	// walidacja (nie moga wykraczac poza plansze)
	int x, y;
	ui.askForCoordinates();
	x = ui.getX();
	y = ui.getY();

	// zaznaczenie strzalu w shotsHistory[][]
	player2.shotsHistory[y][x] = true;

	// sprawdz czy trafienie ktoregos z floty
	for (int i = 0; i < player2.getShips().size(); i++) {
		hit = player2.getShips()[i].handleTheShoot(x,y);
		if (hit) {
			player1.howManyHits++;
		}
	}
}


void GameHandler::secondPlayerMove() {
	//system("cls");
	//system("Color 03");
	//diplayTurnToEnd();
	//std::cout << player2.getName() << " wykonuje swoj ruch." << std::endl;
	//player2.howManyHits++;

	system("cls");
	system("Color 03");
	diplayTurnToEnd();
	std::cout << player2.getName() << " wykonuje swoj ruch." << std::endl;

	// wyswietl plansze
	ui.displayCurrentPlayerBoard(player2);
	std::cout << std::endl;
	ui.displayRivalsBoard(player1);
	std::cout << std::endl;

	bool hit;
	// zapytaj uzytkownika o wspolrzedne strzalu 
	// walidacja (nie moga wykraczac poza plansze)
	int x, y;
	ui.askForCoordinates();
	x = ui.getX();
	y = ui.getY();

	// zaznaczenie strzalu w shotsHistory[][]
	player1.shotsHistory[y][x] = true;

	// sprawdz czy trafienie ktoregos z floty
	for (int i = 0; i < player1.getShips().size(); i++) {
		hit = player1.getShips()[i].handleTheShoot(x, y);
		if (hit) {
			player2.howManyHits++;
		}
	}
}

void GameHandler::getTurnsLimits() {

	while (true) {

		std::cout << "\tEnter number of wanted turns (3-25) >> ", std::cin >> turnLimit;

		if ((turnLimit >= 3) && (turnLimit <=25))
			break;
		else
			std::cout << "Invalid input. Try again!\n" << std::endl;

		system("pause");
		system("cls");
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

	while (player1.howManyHits < 5 && player2.howManyHits < 5 && turnCounter <= turnLimit) {
		// metody z userInterface od Michała o sprawdzaniu strzałów
		changePlayerScreen(player1.getName());
		firstPlayerMove();
		std::cout << "inkrementacja ruchow: " << player1.howManyHits << std::endl;
		//Sleep(1000);

		//isWin

		changePlayerScreen(player2.getName());
		secondPlayerMove();
		std::cout << "inkrementacja 2 ruchow: " << player1.howManyHits << std::endl;
		//Sleep(1000);
		// isWin
		turnCounter++;
	}
	
	inter.displayEndGameSign();
	if ((turnCounter - 1) == turnLimit)
		std::cout << "\n\tNo more turns, it's a draw!" << std::endl;
	else
		displayWhoWin(player1.getName());
}