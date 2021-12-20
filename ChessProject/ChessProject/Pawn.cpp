#include "Pawn.h"

Pawn::Pawn(const char x, const char y, const char name, const bool color) : Soldier(x, y, name, color), _firstMove(true)
{
}

Pawn::~Pawn()
{
}

void Pawn::isValidMove(const string cords, const string* board, const bool currentColor)
{
	char newX = FrontedText::getXorY(cords, 2);
	char newY = FrontedText::getXorY(cords, 3);
	char currentX = this->getX();
	char currentY = this->getY();
	int newXNum = turnCordToInt(newX);
	int newYNum = turnCordToInt(newY);
	int currentXNum = turnCordToInt(currentXNum);
	int currentYNum = turnCordToInt(currentYNum);
	checkIfCordsValid(newX, newY);
	checkIfSourceIsRight(board, currentColor);
	checkIfNotSameIndex(newX, newY);
	checkIfDestNotOwn(newX, newY, board);
	if ((newYNum == currentYNum + 1) || (this->_firstMove && newYNum == currentYNum + 2) || (board[newYNum][newXNum] != '#' && (newXNum == currentXNum + 1 && newYNum == currentYNum + 1 || newXNum == currentXNum - 1 && newYNum == currentYNum + 1)))
	{
		checkIfNotRunOver(turnCordToInt(currentX), turnCordToInt(currentY), newX, newY, board);
	}
	else
	{
		throw moveException::invalidMove();
	}
	throw moveException::validMove();
}

void Pawn::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const
{
	if (startY + 1 == turnCordToInt(y) && startX == turnCordToInt(x))
	{
		
	}
}
