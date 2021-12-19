#include "Queen.h"

Queen::Queen(const char x, const char y, const char name, const bool color) : Rook(x, y, name, color), Bishop(x, y, name, color)
{
}

Queen::~Queen()
{
}

void Queen::isValidMove(const string cords, const string* board, const bool currentColor)
{
	try
	{
		this->Rook::isValidMove(cords, board, currentColor);
	}
	catch (const char e)
	{
		if (e == VALID)
		{
			throw moveException::validMove();
		}
		else
		{
			this->Bishop::isValidMove(cords, board, currentColor);
		}
	}
}
