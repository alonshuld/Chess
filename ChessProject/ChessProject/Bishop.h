#pragma once
#include "Soldier.h"
class Bishop : public Soldier
{
public:
	Bishop(const char x, const char y, const char name, const bool color);
	~Bishop();
	void isValidMove(const string cords, const string* board, const bool currentColor);
	void checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const;
};