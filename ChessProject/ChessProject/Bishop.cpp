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
	int testValid;
	int cx = turnCordToInt(currentX);
	int nx = turnCordToInt(newX);
	int cy = turnCordToInt(currentY);
	int ny = turnCordToInt(newY);
	checkIfCordsValid(newX, newY);
	checkIfSourceIsRight(board, currentColor);
	checkIfNotSameIndex(newX, newY);
	testValid = cx - nx;
	if ((currentX != newX && currentY != newY) && (((cy - ny) == testValid) || (cy - ny) == -testValid))
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
	int j = startY;
	int indexX = turnCordToInt(x);
	int indexY = turnCordToInt(y);
	if (startY < indexY) // goes up
	{
		if (startX < indexX) // goes up right
		{
			for (int i = startX + 1; i < indexX; i++)
			{
				j++;
				if (board[j][i] != '#')
					throw moveException::invalidMove();
			}
		}
		else //goes up left
		{
			for (int i = startX - 1; i > indexX; i--)
			{
				j++;
				if (board[j][i] != '#')
					throw moveException::invalidMove();
			}
		}
	}
	else //goes down
	{
		if (startX < indexX) // goes down right
		{
			for (int i = startX + 1; i < indexX; i++)
			{
				j--;
				if (board[j][i] != '#')
					throw moveException::invalidMove();
			}
		}
		else //goes down left
		{
			for (int i = startX - 1; i > indexX; i--)
			{
				j--;
				if (board[j][i] != '#')
					throw moveException::invalidMove();
			}
		}
	}
}