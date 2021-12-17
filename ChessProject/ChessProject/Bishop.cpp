#include "Bishop.h"
Bishop::Bishop(const char x, const char y, const char name, const bool color) : Soldier(x, y, name, color)
{
}

Bishop::~Bishop()
{
}

void Bishop::isValidMove(const string cords, const string* board, const bool currentColor)
{
	char newX = FrontedText::getXorY(cords, 2);
	char newY = FrontedText::getXorY(cords, 3);
	char currentX = this->getX();
	char currentY = this->getY();
	checkIfCordsValid(newX, newY);
	checkIfSourceIsRight(board, currentColor);
	checkIfNotSameIndex(newX, newY);
	if ((currentX != newX && currentY != newY))
	{
		checkIfDestNotOwn(newX, newY, board);
		checkIfNotRunOver(turnCordToInt(currentX), turnCordToInt(currentY), newX, newY, board);
	}
	else
	{
		throw moveException::invalidMove();
	}
	throw moveException::validMove();
}

void Bishop::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const
{
	int indexX = turnCordToInt(x);
	int indexY = turnCordToInt(y);
	int yCounter = startY - ONE;
	if (startY > indexY)
	{
		if (startX > indexX)
		{
			for (int counter = startX - ONE; counter > indexX; counter--)
			{
				if (board[yCounter][counter] != '#')
				{
					throw moveException::invalidMove();
				}
				yCounter--;
			}
		}
		else
		{
			for (int counter = startX + ONE; counter < indexX; counter++)
			{
				if (board[yCounter][counter] != '#')
				{
					throw moveException::invalidMove();
				}
				yCounter--;
			}
		}
	}
	if (startY < indexY)
	{
		yCounter += TWO;
		if (startX > indexX)
		{
			for (int counter = startX - ONE; counter > indexX; counter--)
			{
				if (board[yCounter][counter] != '#')
				{
					throw moveException::invalidMove();
				}
				yCounter++;
			}
		}
		else
		{
			for (int counter = startX + ONE; counter < indexX; counter++)
			{
				if (board[yCounter][counter] != '#')
				{
					throw moveException::invalidMove();
				}
				yCounter++;
			}
		}
	}
}