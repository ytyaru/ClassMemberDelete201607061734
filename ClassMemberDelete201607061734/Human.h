#pragma once
#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>
#include "Item.h"

class Human
{
public:
	Human(void);
	~Human(void);
	
	Item item;
	Item* pItem;

};
