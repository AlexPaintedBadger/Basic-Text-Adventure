#include "Inventory.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;


string slot1 = "Empty";
string slot2 = "Empty";
string slot3 = "Empty";
string slot4 = "Empty";
string in;
int numIn;


Inventory::Inventory() {

};

void Inventory::DropInventory(int invNum)
{
		if (invNum == 1) {
			slot1 = "Empty";
			cout << "The item in slot 1 has been dropped.";
		}
		else if (invNum == 2) {
			slot2 = "Empty";
			cout << "The item in slot 2 has been dropped.";
		}
		else if (invNum == 3) {
			slot3 = "Empty";
			cout << "The item in slot 3 has been dropped.";
		}
		else if (invNum == 4) {
			slot4 = "Empty";
			cout << "The item in slot 4 has been dropped.";
		}
};

void Inventory::AddInventory(string item)
{
	if (slot1 == "Empty"){
		slot1 = item;
		cout << item + " has been put in slot 1.\n";
	}
	else if (slot2 == "Empty") {
		slot2 = item;
		cout << item + " has been put in slot 2.\n";
	}
	else if (slot3 == "Empty") {
		slot3 = item;
		cout << item + " has been put in slot 3.\n";
	}
	else if (slot4 == "Empty") {
		slot4 = item;
		cout << item + " has been put in slot 4.\n";
	}
	else {
		cout << "Your inventory is full. Would you like to swap it with something?\n";
		cout << "> Yes    > No\n\n";
		cin >> in;
		transform(in.begin(), in.end(), in.begin(), ::tolower);
		if (in == "yes") {
			DisplayInventory();
			cout << "What slot would you like to swap it with?\n";
			cin >> numIn;
			DropInventory(numIn);
			AddInventory(item);
		}
	}
};

void Inventory::DisplayInventory()
{
	cout << "Here's what's in your inventory:\n";
	cout << "Slot 1: " + slot1 << endl;
	cout << "Slot 2: " + slot2 << endl;
	cout << "Slot 3: " + slot3 << endl;
	cout << "Slot 4: " + slot4 << endl;
}

string Inventory::returnInvSlot(int slotNum)
{
	if (slotNum == 1) {
		return slot1;
	}
	else if (slotNum == 2) {
		return slot2;
	}
	else if (slotNum == 3) {
		return slot3;
	}
	else if (slotNum == 4) {
		return slot4;
	}
	return "That slot does not exist.";
}

void Inventory::clearInvSlot(int invNum)
{
		if (invNum == 1) {
			slot1 = "Empty";
		}
		else if (invNum == 2) {
			slot2 = "Empty";
		}
		else if (invNum == 3) {
			slot3 = "Empty";
		}
		else if (invNum == 4) {
			slot4 = "Empty";
		}
};

void Inventory::clearInventory()
{
	slot1 = "Empty";
	slot2 = "Empty";
	slot3 = "Empty";
	slot4 = "Empty";
}