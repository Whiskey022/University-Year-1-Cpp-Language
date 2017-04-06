#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//for keyboard input
#include <Windows.h>
#include <conio.h>

using namespace std;

#include "maze.h"

void MainMenu();
void MazeMenu();
void StartGame(string mazeNumber);
void PrintScores(string level);
void PrintCredits();

int main()
{
	while (1) {
		MainMenu();
		int keyInput=getch();
		//menu to choose a game
		if (keyInput == '1') {
			MazeMenu();
			while (1) {
				keyInput = getch();
				if (keyInput == '1') {
					StartGame("01");
				}
				else if (keyInput == '2') {
					StartGame("02");
				}
				else if (keyInput == '3') {
					StartGame("03");
				}
				else if (keyInput == '4') {
					StartGame("04");
				}
				else if (keyInput == '5') {
					StartGame("05");
				}
				else if (keyInput == '6'){
					break;
				}
			}
		}
		//menu to choose which high scores to print
		else if (keyInput == '2') {
			MazeMenu();
			while (1) {
				keyInput = getch();
				if (keyInput == '1') {
					PrintScores("01");
					break;
				}
				else if (keyInput == '2') {
					PrintScores("02");
					break;
				}
				else if (keyInput == '3') {
					PrintScores("03");
					break;
				}
				else if (keyInput == '4') {
					PrintScores("04");
					break;
				}
				else if (keyInput == '5') {
					PrintScores("05");
					break;
				}
				else if (keyInput == '6') {
					break;
				}
			}
		}
		//credits
		else if (keyInput == '3') {
			PrintCredits();
		}
		//exit
		else if (keyInput == '4') {
			break;
		}
	}
	return 0;
}


//function to start a maze game
void StartGame(string mazeNumber)
{
	Maze maze(mazeNumber);
	maze.PrintMaze();

	//key input nicked from this forum http://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key

	int keyInput;
	bool continueGame = true;
	while (continueGame) {
		switch ((keyInput = getch())) {
			//up
		case 72:
			continueGame = maze.ChangePlayerPosition(0, -1);
			break;
			//down
		case 80:
			continueGame = maze.ChangePlayerPosition(0, 1);
			break;
			//left
		case 75:
			continueGame = maze.ChangePlayerPosition(-1, 0);
			break;
			//right
		case 77:
			continueGame = maze.ChangePlayerPosition(1, 0);
			break;
		}
	}
}

//prints scores to the screen
void PrintScores(string level)
{
	system("cls");
	cout << "High Scores" << endl<<endl;
	//file name from which scores will be read
	string fileName = "times_" + level + ".txt";
	ifstream finput(fileName);


	//reading data
	//data is saved by the format example:
	//   1|Tom|15.201
	string st;
	char temp;
	int pos=0;
	double time;
	while (!finput.eof()) {
		pos = 0;
		finput >> pos;
		//if failed to read a position, break loop
		if (pos == 0)
			break;
		finput >> temp;
		getline(finput, st, '|');
		finput >> time;
		cout << pos << ". " << st << "   " << time << endl;

	}
	int keyInput = getch();
}

void MainMenu() {
	system("cls");

	cout << "++++++++ Shitty Maze Game +++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++" << endl << endl;
	cout << "1. Play" << endl;
	cout << "2. High scores" << endl;
	cout << "3. Credits" << endl;
	cout << "4. Exit" << endl;
}

void MazeMenu() {
	system("cls");

	cout << "++++++++ Shitty Maze Game +++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++" << endl << endl;
	cout << "1. Maze 01" << endl;
	cout << "2. Maze 02" << endl;
	cout << "3. Maze 03" << endl;
	cout << "4. Maze 04" << endl;
	cout << "5. Maze 05" << endl;
	cout << "6. Cancel" << endl;
}

void PrintCredits()
{
	system("cls");
	cout << "++++++++ Shitty Maze Game +++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++" << endl << endl;
	cout << "Developed by.............Viskantas Juodenas" << endl;
	cout << "Directed by..............Viskantas Juodenas" << endl;
	cout << "Studio Manager...........Viskantas Juodenas" << endl;
	cout << "Head of Production.......Viskantas Juodenas" << endl;
	cout << "Design Director..........Viskantas Juodenas" << endl;
	cout << "Animation Director.......Viskantas Juodenas" << endl;
	cout << "Special Thanks To........Viskantas Juodenas" << endl;
	int keyInput = getch();
}