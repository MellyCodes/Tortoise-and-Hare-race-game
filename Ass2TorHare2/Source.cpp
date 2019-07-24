/**
* @file Source.cpp //(ASSIGNMENT 2 TORT AND HARE)
* @author Melanie Roy-Plommer
* @version 1.0
*
*
* @section DESCRIPTION
* < Tortoise and Hare race game using Inheritance and Polymorphism >
*
*
* @section LICENSE
*
*
* Copyright 2018
* Permission to use, copy, modify, and/or distribute this software for
* any purpose with or without fee is hereby granted, provided that the
* above copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
* @section Academic Integrity
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
**/

//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)
//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)
//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)
//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)
//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)
//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)
//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)//(ASSIGNMENT 2 TORT AND HARE)


#include "Racer.h"
#include "Hare.h"
#include "Tortoise.h"
#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <string>
#include <vector>
#include <Windows.h>

// Variables
static std::string raceWinnerMessage = "";

// Constants
static const int HEATS_TO_WIN = 10; //Number of heats needed to win the race
static const int REFRESH_TIME = 50; //sleep time between moves in a heat
static const int TRACK_WIDTH = 100; // Track width displayed
static const int WIN_POSITION = 70; // Position needed to win heat

// Forward Declarations
void printMenu();  // Prints menu at the start
bool raceOrQuit(); //Gets the user's decision to either play or quit the application
void displayRace(std::vector<Racer*> racers, int trackWidth); //Displays the progress of the race as it's happening
int getUserInt(std::string q); //Asks the user how many hares or tortoises are in the race and returns that number
void play(); // Play the game 
void heat(std::vector<Racer*> racers); // Heat 
void race(std::vector<Racer*> racers); // Race
std::string getPositionString(int position); // String for displaying asterisks during races
void setWinnerMessage(Racer* r); // sets the message below the menu with the name and type of winner
void promptToContinue(); // end of application C to quit


//Main Program
int main()
{
	srand(time(NULL));
	while (true)
	{
		system("cls");
		printMenu();
		std::cout << raceWinnerMessage << std::endl;
		if (raceOrQuit())
		{
			play();
		}
		else
		{
			break;
		}
	}

	std::cout << "you quit" << std::endl;
	promptToContinue();
}

// Function Definitions

// Prints menu at the start
void printMenu()
{
	std::cout << "*************************************" << std::endl
		<< "*                                   *" << std::endl
		<< "*  (R) Start a new Race             *" << std::endl
		<< "*  (Q) Quit                         *" << std::endl
		<< "*                                   *" << std::endl
		<< "*************************************\n";
}

//Gets the user's decision to either play or quit the application
bool raceOrQuit()
{
	char decision;
	std::cin >> decision;

	while (true) {
		if (toupper(decision) == 'R')
		{
			return true;
		}
		else if (toupper(decision) == 'Q')
		{
			return false;
		}
		else // If user enters anything else, like a number application quits
		{
			return false;
		}
	}
}

//Displays the progress of the race as it's happening
void displayRace(std::vector<Racer*> racers, int trackWidth)
{
	system("cls");

	std::cout << "Racer" << ":\t" << "Wins" << ":\t" << "Track" << std::endl;

	for (Racer *r : racers)
	{
		std::cout << r->getName() << ":\t" << r->getWins() << ":\t" << getPositionString(r->getPosition()) << std::endl;
	}
}

//Asks the user how many hares or tortoises are in the race and returns that number
int getUserInt(std::string q)
{
	int number;
	std::cout << q << std::endl;
	std::cin >> number;
	return number;
}

// PLay the game  
void play()
{
	std::string howManyHares = "How many hares are racing?";
	std::string howManyTorts = "How many tortoises are racing?";

	//Call function to ask user how many hares
	int numberOfHares = getUserInt(howManyHares);

	//Call function to ask user how many tortoises
	int numberOfTortoises = getUserInt(howManyTorts);

	std::vector<Racer*> racers;

	//add hares
	for (int i = 1; i <= numberOfHares; i++)
	{
		Racer* tmp = new Hare();
		racers.push_back(tmp);
	}

	//add tortoise
	for (int i = 1; i <= numberOfTortoises; i++)
	{
		Racer* tmp = new Tortoise();
		racers.push_back(tmp);
	}

	race(racers);
}

//Heat
void heat(std::vector<Racer*> racers)
{
	// return to starting blocks
	for (Racer *r : racers)
	{
		r->resetPosition();
	}

	bool heatWon = false;

	// moves loop terminates when a racer wins a single heat	
	while (!heatWon)
	{
		//moving racers
		for (Racer *r : racers)
		{
			r->move(rand());

			// if we have a heat winner
			if (r->getPosition() == WIN_POSITION)
			{
				r->incrementWins();
				heatWon = true;// breaks loop and terminates heat;				
				break;
			}
		}

		//Function call to display progress of each heat
		displayRace(racers, TRACK_WIDTH);
		// pause
		Sleep(REFRESH_TIME);
	}
}

//Race
void race(std::vector<Racer*> racers)
{
	bool raceWon = false;

	//each time  round is a single heat
	while (!raceWon)// heats loop terminates when a racer wins 10 heats
	{
		heat(racers);

		// check for winner of 10 heats
		for (Racer *r : racers) {
			// if we have a race winner (10 heats)
			if (r->getWins() == HEATS_TO_WIN) {
				setWinnerMessage(r);
				raceWon = true; // breaks outer loop and terminates race.

				break;
			}
		}

	}

	// Race over, deleting racers
	for (Racer *r : racers) {
		delete r;
	}
}

// String for displaying asterisks during races
std::string getPositionString(int position)
{
	std::string track = "";
	for (int i = 0; i < ((static_cast<double>(TRACK_WIDTH) / WIN_POSITION)* position); i++)
	{
		track += "*";
	}
	return track;
}

// sets the message below the menu with the name and type of winner
void setWinnerMessage(Racer* r)
{
	raceWinnerMessage = "Racer " + r->getName() + ", a " + r->getType() + " won the race!";
}

// end of application C to quit
void promptToContinue() {

	std::cout << "Press C to continue ... ";
	char c;
	std::cin >> c;

	while (toupper(c) != 'C')
	{
		std::cin >> c;
	}
}
