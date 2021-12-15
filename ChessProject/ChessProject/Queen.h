#pragma once
#include "Rook.h"
class Queen : public Rook 
{
public:
	Queen(const char x, const char y, const char name, const bool color);
	~Queen();
	void isValidMove(const string cords, const string* board, const bool currentColor) override;
};