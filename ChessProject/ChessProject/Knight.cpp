#include "Knight.h"

/*
this function will creat Knight soldier
input: x, y, name, color
output: none
*/
Knight::Knight(const char x, const char y, const char name, const bool color) : Soldier(x, y, name, color)
{
}

/*
this function will be used as a Knight dtor
input: none
output: none
*/
Knight::~Knight()
{
}

/*
this function will check if the soldier is making a valid move or not
input: cords, board, currentColor
output: none
*/
void Knight::isValidMove(const string cords, const string* board, const bool currentColor)
{
	char newX = FrontedText::getXorY(cords, TWO);
	char newY = FrontedText::getXorY(cords, THREE);
	char currentX = this->getX();
	char currentY = this->getY();
	checkIfCordsValid(newX, newY);
	checkIfSourceIsRight(board, currentColor);
	checkIfNotSameIndex(newX, newY);
	if ((currentX - ONE == newX && currentY + TWO == newY) || (currentX - ONE == newX && currentY - TWO == newY) ||
		(currentX - TWO == newX && currentY - ONE == newY) || (currentX - TWO == newX && currentY + ONE == newY) || (currentX - ONE == newX && currentY - ONE == newY) || (currentX + ONE == newX && currentY - TWO == newY) ||
		(currentX + ONE == newX && currentY + TWO == newY) || (currentX + TWO == newX && currentY + ONE == newY) || (currentX + TWO == newX && currentY - ONE == newY))
	{
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
void Knight::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const
{
	checkIfDestNotOwn(x, y, board);
}
