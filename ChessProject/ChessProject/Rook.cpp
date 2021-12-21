#include "Rook.h"
#include <iostream>

/*
this function will create a rook object
input: x, y, name, color
output: none
*/
Rook::Rook(const char x, const char y, const char name, const bool color) : Soldier(x, y, name, color)
{
}

/*
this function will be used as a Rook dtor
input: none
output: none
*/
Rook::~Rook()
{
}

/*
this function will check if the soldier is making a valid move or not
input: cords, board, currentColor
output: none
*/
void Rook::isValidMove(const string cords, const string* board, const bool currentColor)
{
	char newX = FrontedText::getXorY(cords, TWO);
	char newY = FrontedText::getXorY(cords, THREE);
	char currentX = this->getX();
	char currentY = this->getY();
	checkIfCordsValid(newX, newY);
	checkIfSourceIsRight(board, currentColor);
	checkIfNotSameIndex(newX, newY);
	if (((currentX == newX && currentY != newY) || (currentX != newX && currentY == newY)))
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


/*
this function will check if the soldier isnt running over other soldier while moving
input: startX, startY, x, y, board
output: none
*/
void Rook::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const
{
	int indexX = turnCordToInt(x);
	int indexY = turnCordToInt(y);
	if (indexX == startX)
	{
		if (startY > indexY)
		{
			for (int i = indexY + ONE; i < startY; i++)
				if (board[i][startX] != '#')
					throw moveException::invalidMove();
		}
		else
		{
			for (int i = startY + ONE; i < indexY; i++)
				if (board[i][startX] != '#')
					throw moveException::invalidMove();
		}
	}
	else
	{
		if (startX > indexX)
		{
			for (int i = indexX + ONE; i < startX; i++)
				if (board[startY][i] != '#')
					throw moveException::invalidMove();
		}
		else
		{
			for (int i = startX + ONE; i < indexX; i++)
				if (board[startY][i] != '#')
					throw moveException::invalidMove();
		}
	}
}
