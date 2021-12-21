#include "King.h"

/*
this function will creat king soldier
input: x, y, name, color
output: none
*/
King::King(const char x, const char y, const char name, const bool color) : Soldier(x, y, name, color)
{
}

/*
this function will be used as a king dtor
input: none
output: none
*/
King::~King()
{
}

/*
this function will check if the soldier is making a valid move or not
input: cords, board, currentColor
output: none
*/
void King::isValidMove(const string cords, const string* board, const bool currentColor)
{
	char newX = FrontedText::getXorY(cords, TWO);
	char newY = FrontedText::getXorY(cords, THREE);
	char currentX = this->getX();
	char currentY = this->getY();
	checkIfCordsValid(newX, newY);
	checkIfSourceIsRight(board, currentColor);
	checkIfNotSameIndex(newX, newY);
	if ((currentX + ONE == newX && currentY == newY + ONE) || (currentX - ONE == newX && currentY + ONE == newY) ||
		(currentX == newX && currentY + ONE == newY) || (currentX == newX && currentY - ONE == newY) || (currentX - ONE == newX && currentY - ONE == newY) || (currentX + ONE == newX && currentY - ONE == newY) ||
		(currentX + ONE == newX && currentY == newY) || (currentX - ONE == newX && currentY == newY))
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
void King::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const
{
	checkIfDestNotOwn(x, y, board);
}