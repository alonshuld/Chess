#include "King.h"

King::King(const char x, const char y, const char name, const bool color) : Soldier(x, y, name, color)
{
}

King::~King()
{
}

void King::isValidMove(const string cords, const string* board, const bool currentColor)
{
	char newX = FrontedText::getXorY(cords, 2);
	char newY = FrontedText::getXorY(cords, 3);
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

void King::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const
{
	checkIfDestNotOwn(turnCordToInt(x), turnCordToInt(y), board);
}
