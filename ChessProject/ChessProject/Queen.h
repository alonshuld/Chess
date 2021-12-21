#pragma once
#include "Bishop.h"

class Queen : public Bishop
{
public:
	Queen(const char x, const char y, const char name, const bool color);
	~Queen();
	void isValidMove(const string cords, const string* board, const bool currentColor) override;
	void checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board);
};