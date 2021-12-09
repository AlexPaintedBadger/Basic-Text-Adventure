// Basic Text Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Inventory.h"
#include "GameScenes.h"
using namespace std;

GameScenes mainGame;

int main()
{
    cout << "Welcome to Basic Text Adventure!\n";
    system("pause");
    mainGame.startGame();
}
