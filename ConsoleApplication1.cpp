/*  Project Name: Chapter 6 Exercise 16
    File Name: ConsoleApplication1.cpp
    Programmer: Harrison Hudgins
    Date: December 10, 2024
    Requirements:
    For this programming problem, download the following files from the book’s companion website:
    • Teams.txt—This file contains a list of several Major League baseball teams in alphabetical order. Each team listed in the file has won the World Series at least once.
    • WorldSeriesWinners.txt—This file contains a chronological list of the World Series’ winning teams from 1903 to 2012. (The first line in the file is the name of the team that won in 1903, and the last line is the name of the team that won in 2012. Note the World Series was not played in 1904 or 1994.)
    Write a program that displays the contents of the Teams.txt file on the screen and prompts the user to enter the name of one of the teams. The program should then display the number of times that team has won the World Series in the time period from 1903 to 2012.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string teams = "Teams.txt";
string teamArray[29];
string winnerArray[106];

string winners = "WorldSeriesWinners.txt";

void startArray() {
    ifstream teamFile;
    teamFile.open(teams);
    string line;
    for (int team = 0; team < 29; team++) {
        getline(teamFile, line);
        teamArray[team] = line;
    }
    teamFile.close();
}

void displayTeams() {
    for (int team = 0; team < 29; team++) {
        cout << teamArray[team] << endl;
    }
}

string teamChoice() {
    bool teamChoice = false;
    string choice;
   
    cout << "Pick a team from the list below:\n";
    displayTeams();

    while (teamChoice == false) {
        cout << "Choice: ";
        getline(cin, choice);
        for (int team = 0; team < 29; team++) {
            if (choice == teamArray[team]) {
                teamChoice = true;
            }
        }
    }
    cout << endl;
    return choice;
}

void winnersArray() {
    ifstream winnerFile;
    winnerFile.open(winners);
    string line;
    for (int team = 0; team < 106; team++) {
        getline(winnerFile, line);
        winnerArray[team] = line;
    }
    winnerFile.close();
}

int timesWon(string choice) {
    winnersArray();
    int wonCount = 0;
    for (int team = 0; team < 106; team++) {
        if (choice == winnerArray[team]) {
            wonCount++;
        }
    }
    return wonCount;
}

int main() {
    startArray();
    cout << "The team has won " << timesWon(teamChoice()) << " times.";
}
