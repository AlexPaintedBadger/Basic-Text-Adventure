#ifndef _HEADER_INVENTORY
#define _HEADER_INVENTORY
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Inventory
{
public:
	Inventory();
	void DropInventory(int invNum);
	void AddInventory(string item);
	void DisplayInventory();
	string returnInvSlot(int slotNum);
	void clearInvSlot(int invNum);
	void clearInventory();
};

#endif
