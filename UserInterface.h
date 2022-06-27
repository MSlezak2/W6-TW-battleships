#pragma once
class UserInterface {
public:
	void welcomeScreen(); // ekran powitalny (gdzie user ma wybor - "graj" albo "help")
	void help(); // ekran z instrukcja
	void displayResults(); // ekran na koniec gry (kto wygral itd)
	void displayCurrentPlayerBoard();  // wyswietl moja plansze (moje statki i ich stan)
	void displayRivalsBoard(); // wyswietl plansze przeciwnika (gdzie juz strzelalem, co trafilem, co zaptopilem itd.)
	void askForCoordinates(int& x, int& y); // od razu waliduje czy podany input jest wspolrzedna, i czy nie wykracza poza ramy

private:
};

