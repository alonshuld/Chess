#pragma once
#include "Soldier.h"
class Rook : public Soldier
{
public:
	Rook(const char x, const char y, const char name, const bool color);
	~Rook();
	void isValidMove(const string cords, const string* board, const bool currentColor);
	void checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const;
};