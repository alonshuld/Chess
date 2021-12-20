#pragma once

#include "Soldier.h"

class Pawn : public Soldier
{
public:
	Pawn(const char x, const char y, const char name, const bool color);
	~Pawn();
	void isValidMove(const string cords, const string* board, const bool currentColor);
	void checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const;
private:
	bool _firstMove;
	
};