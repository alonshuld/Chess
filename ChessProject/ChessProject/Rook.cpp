#include "Rook.h"

Rook::Rook(const char x, const char y, const char name, const bool color) : Soldier(x, y, name, color)
{
}

Rook::~Rook()
{
}

void Rook::isValidMove(const string cords, const string* board)
{
	char newX = FrontedText::getXorY(cords, 2);
	char newY = FrontedText::getXorY(cords, 3);
	char currentX = getX();
	char currentY = getY();
	checkIfCordsValid(newX, newY);
	checkIfNotSameIndex(newX, newY);
	if ((getX() == newX && getY() != newY) || (getX() != newX && getY() == newY))
	{
		checkIfDestNotOwn(newX, newY, board);
		if(newX != getX())
			checkIfNotRunOver(turnCordToInt(currentX) + 1, turnCordToInt(currentY), newX, newY, board);
		else
			checkIfNotRunOver(turnCordToInt(currentX), turnCordToInt(currentY) + 1, newX, newY - 1, board);
	}
	else
	{
		throw moveException::invalidMove();
	}
	setCords(newX, newY);
	throw moveException::validMove();
}

void Rook::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const
{
	int indexX = turnCordToInt(x);
	int indexY = turnCordToInt(y);
	for (int counter = startY; counter < indexY; counter++)
	{
		for (int secCounter = startX; secCounter < indexX; secCounter++)
		{
			if (board[counter][secCounter] != '#')
			{
				throw moveException::invalidMove();
			}
		}
	}
}
