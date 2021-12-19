#include "Knight.h"
Knight::Knight(const char x, const char y, const char name, const bool color) : Soldier(x, y, name, color)
{
}

Knight::~Knight()
{
}

void Knight::isValidMove(const string cords, const string* board, const bool currentColor)
{
	char newX = FrontedText::getXorY(cords, 2);
	char newY = FrontedText::getXorY(cords, 3);
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

void Knight::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const
{
	checkIfDestNotOwn(x, y, board);
}
