#include "GameScenes.h"
#include "Inventory.h"
#include <stdlib.h>
#include <algorithm>
#include <cctype>
#include <ciso646>
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

string input;
string temp;
Inventory inv1;
int numEndingsAchieve = 0;
int chilliEatCount = 0;
int chilliOrdered = 0;
string endings[6] = {"???", "???", "???", "???", "???", "???"};

GameScenes::GameScenes()
{
}

void GameScenes::startGame()
{
	cout << "What would you like to do?\n";
	cout << "> Start Game    > Check Stats    > Exit Game\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "start game" || input == "start") {
		beginningScene();
	}
	else if (input == "check stats" || input == "stats") {
		checkStats();
	}
	else if (input == "exit game" || input == "exit") {

	}
	else {
		cout << "That isn't an option.\n";
		startGame();
	}
}

void GameScenes::checkStats()
{
	cout << "Number of endings achieved: " + numEndingsAchieve << endl;
	cout << "Endings:\n";
	for (int i = 0; i < 6; i++) {
		cout << endings[i] << endl;
	}
	startGame();
}

void GameScenes::beginningScene()
{
	cout << "\n\nWhere would you like to go?\n";
	cout << "> House    > Beach    > Wendy's    > Nowhere\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "wendy's")
	{
		wendys();
	}
	else if (input == "nowhere") {
		nowhere();
	}
}

void GameScenes::wendys()
{
	cout << "You suddenly feel extremely hungry and are in need of some food.\n";
	cout << "You decide it would be a good idea to go to Wendy's. When you open\n";
	cout << "the door, you see an absurdly large man waiting in line.\n";
	cout << "Do you get in line for food?\n";
	cout << "> Yes    > No\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "yes") {
		cout << "You stand in line and hear the man in front of you order\n";
		cout << "five bowls of chilli and three Pepsis. You become a bit frightened,\n";
		cout << "but continue on with your day.\n";
		orderFood();
	}
	else if (input == "no") {
		cout << "You decide it would be a better idea to leave the building.\n";
		startGame();
	}
}

void GameScenes::orderFood()
{
	cout << "You get up to the register and the lady asks you if you\n";
	cout << "would like a bowl of chilli or a Pepsi.\n";
	cout << "> Chilli     > Pepsi    > Both    > Neither\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "chilli") {
		inv1.AddInventory("chilli");
		chilliOrdered++;
		orderAgain();
	}
	else if (input == "pepsi") {
		inv1.AddInventory("pepsi");
		inv1.DisplayInventory();
		orderAgain();
	}
	else if (input == "both") {
		inv1.AddInventory("pepsi");
		inv1.AddInventory("chilli");
		inv1.DisplayInventory();
		orderAgain();
	}
	else if (input == "neither") {
		eatFood();
	}
	else {
		cout << "That isn't an option.\n";
		orderFood();
	}
}

void GameScenes::orderAgain()
{
	cout << "Would you like to order anything else?\n";
	cout << "> Chilli     > Pepsi    > Both    > Neither\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "chilli") {
		if (chilliOrdered != 15) {
			inv1.AddInventory(input);
			chilliOrdered++;
			
		}
		else {
			cout << "Sorry, we are all out of chilli.\n";
		}
		orderAgain();
	}
	else if (input == "pepsi") {
		inv1.AddInventory(input);
		orderAgain();
	}
	else if (input == "both") {
		inv1.AddInventory("pepsi");
		inv1.AddInventory("chilli");
		orderAgain();
	}
	else if (input == "neither") {
		eatFood();
	}
	else {
		cout << "That isn't an option.\n";
		orderAgain();
	}
}

void GameScenes::eatFood()
{
	if (chilliEatCount == 15) {
		cout << "You have eaten too much chilli, and Liquid Richard has noticed.\n";
		cout << "He does not like the fact that you ate all the chilli.\n";
		endingBanWorld();
	}
	cout << "Would you like to eat any food or have a drink?\n";
	cout << "> Yes    > No\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "yes" && inv1.returnInvSlot(1) == "Empty" && inv1.returnInvSlot(2) == "Empty" && inv1.returnInvSlot(3) == "Empty" && inv1.returnInvSlot(4) == "Empty") {
		cout << "You don't have anything in your inventory.\n";
		eatFood();
	}
	else if (input == "yes") {
		cout << "From which slot would you like to eat or drink?\n";
		cout << "> Slot 1    > Slot 2    > Slot 3    > Slot 4\n\n";
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		if (input == "slot 1" || input == "1") {
			temp = inv1.returnInvSlot(1);
			if (temp == "chilli") {
				cout << "You have eaten chilli.\n";
				chilliEatCount++;
				inv1.clearInvSlot(1);
				eatFood();
			}
			else if (temp == "pepsi") {
				cout << "You drank the Pepsi.\n";
				inv1.clearInvSlot(1);
				eatFood();
			}
			else if (temp == "Empty") {
				cout << "That inventory slot is empty.";
				eatFood();
			}
			else {
				cout << "Sorry, you can't eat that.\n";
				eatFood();
			}
		} 
		else if (input == "slot 2" || input == "2") {
			temp = inv1.returnInvSlot(2);
			if (temp == "chilli") {
				cout << "You have eaten chilli.\n";
				chilliEatCount++;
				inv1.clearInvSlot(2);
				eatFood();
			}
			else if (temp == "pepsi") {
				cout << "You drank the Pepsi.\n";
				inv1.clearInvSlot(2);
				eatFood();
			}
			else if (temp == "Empty") {
				cout << "That inventory slot is empty.";
				eatFood();
			}
			else {
				cout << "Sorry, you can't eat that.\n";
				eatFood();
			}
		} 
		else if (input == "slot 3" || input == "3") {
			temp = inv1.returnInvSlot(3);
			if (temp == "chilli") {
				cout << "You have eaten chilli.\n";
				chilliEatCount++;
				inv1.clearInvSlot(3);
				eatFood();
			}
			else if (temp == "pepsi") {
				cout << "You drank the Pepsi.\n";
				inv1.clearInvSlot(3);
				eatFood();
			}
			else if (temp == "Empty") {
				cout << "That inventory slot is empty.";
				eatFood();
			}
			else {
				cout << "Sorry, you can't eat that.\n";
				eatFood();
			}
		}
		else if (input == "slot 4" || input == "4") {
			temp = inv1.returnInvSlot(4);
			if (temp == "chilli") {
				cout << "You have eaten chilli.\n";
				chilliEatCount++;
				inv1.clearInvSlot(4);
				eatFood();
			}
			else if (temp == "pepsi") {
				cout << "You drank the Pepsi.\n";
				inv1.clearInvSlot(4);
				eatFood();
			}
			else if (temp == "Empty") {
				cout << "That inventory slot is empty.";
				eatFood();
			}
			else {
				cout << "Sorry, you can't eat that.\n";
				eatFood();
			}
		}
		else {
			cout << "That inventory slot doesn't exist.\n";
			eatFood();
		}
	}
	else {
		cout << "Would you like to order more food?\n";
		cout << "> Yes    > No\n\n";
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		if (input == "yes") {
			orderFood();
		}
		else {

		}
	}
}

void GameScenes::endingBanWorld()
{
	cout << "Richard does not like your actions, and thus you have\n";
	cout << "been sentenced to life in Ban World.\n";
	cout << "\"Welcome to Ban World, population: you.\"\n\n";
	if (endings[0] == "???") {
		cout << "Ending Achieved: BanWorld\n";
		endings[0] = "BanWorld - Achieved";
		numEndingsAchieve++;
	}
	chilliEatCount = 0;
	chilliOrdered = 0;
	inv1.clearInventory();
	startGame();

}

void GameScenes::nowhere()
{
	cout << "You stand still in the middle of nowhere, going nowhere.\n";
	cout << "Would you like to go anywhere?\n";
	cout << "> House    > Beach    > Wendy's    > Still Nowhere\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "wendy's" || input == "wendys") {
		wendys();
	} if (input == "still nowhere" || input == "nowhere") {
		stillNowhere();
	}
}

void GameScenes::stillNowhere() 
{
	cout << "You continue to stand still, wasting your life away doing nothing.\n";
	cout << "Would you please go somewhere this time?\n";
	cout << "> House    > Beach    > Wendy's    > Still Nowhere\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "wendy's" || input == "wendys") {
		wendys();
	}
	else if (input == "still nowhere" || input == "nowhere") {
		stillStillNowhere();
	}
}

void GameScenes::stillStillNowhere() 
{
	cout << "You still stand there, wondering why you aren't doing anything\n";
	cout << "productive. You contemplate whether it would be better to stand\n";
	cout << "Go somewhere else. Now.\n";
	cout << "> House    > Beach    > Wendy's\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "wendy's" || input == "wendys") {
		wendys();
	}
	else if (input == "nowhere") {
		stillStillStillNowhere();
	}

}

void GameScenes::stillStillStillNowhere()
{
	cout << "What the hell?! That's not even an option! Stop standing there!\n";
	cout << "I demand you go elsewhere!\n";
	cout << "> House    > Beach    > Wendy's\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input == "wendy's" || input == "wendys") {
		wendys();
	}
	else if (input == "nowhere") {
		endingUnproductive();
	}
}

void GameScenes::endingUnproductive()
{
	cout << "I can't do it! I can't take this shit no more, man!\n";
	cout << "You've gone nowhere for too long! We're starting this damn game over again!\n\n";
	if (endings[1] == "???") {
		cout << "Ending Achieved: Unproductive\n";
		endings[1] = "Unproductive - Achieved";
		numEndingsAchieve++;
	}
	inv1.clearInventory();
	startGame();
	
}