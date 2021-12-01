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
	if ((currentX == newX && currentY != newY) || (currentX != newX && currentY == newY))
	{
		checkIfDestNotOwn(newX, newY, board);
		checkIfNotRunOver(turnCordToInt(currentX), turnCordToInt(currentY), newX, newY, board);
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
	if (indexX == startX)
	{
		if (startY > indexY)
		{
			for (int i = indexY + 1; i < startY; i++)
				if (board[i][startX] != '#')
					throw moveException::invalidMove();
		}
		else
		{
			for (int i = startY + 1; i < indexY; i++)
				if (board[i][startX] != '#')
					throw moveException::invalidMove();
		}
	}
	else
	{
		if (startX > indexX)
		{
			for (int i = indexX + 1; i < startX; i++)
				if (board[startY][i] != '#')
					throw moveException::invalidMove();
		}
		else
		{
			for (int i = startX + 1; i < indexX; i++)
				if (board[startY][i] != '#')
					throw moveException::invalidMove();
		}
	}
}